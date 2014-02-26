#include "stdafx.h"
#include "ScriptCaller.h"

// --------------------------------------------------
// public members

ScriptCaller::ScriptCaller(HWND chartWindowHandle)
: m_chartWindowHandle(chartWindowHandle),
    m_rootWindowHandle(NULL),
    m_navigatorTreeViewHandle(NULL)
{

}

// --------------------------------------------------
// private members

const wchar_t* ScriptCaller::NAVIGATOR_WINDOW_CLASS_NAME = L"SysTreeView32";

bool ScriptCaller::callScript(const wchar_t* scriptName)
{
    HWND treeViewHandle = findNavigatorTreeView();
    if (!treeViewHandle) {
        return false;
    }

    int scriptOrdinal = findScriptOrdinal(scriptName);
    if (scriptOrdinal == 0) {
        return false;
    }

    std::wstringstream msg;
    msg << "script name = " << scriptName
        << ", ordinal = " << scriptOrdinal;
    OutputDebugStringW(msg.str().c_str());

    return true;
}

HWND ScriptCaller::getRootWindowHandle()
{
    if (!m_rootWindowHandle) {
        HWND hwnd = m_chartWindowHandle;
        while (true) {
            HWND parent = GetParent(hwnd);
            if (!parent) {
                m_rootWindowHandle = hwnd;
                break;
            }

            hwnd = parent;
        }
    }

    return m_rootWindowHandle;
}

HWND ScriptCaller::findNavigatorTreeView()
{
    if (!m_navigatorTreeViewHandle) {
        HWND rootWindowHandle = getRootWindowHandle();
        EnumChildWindows(rootWindowHandle, staticEnumChildWindowCallback, reinterpret_cast<LPARAM>(this));
    }

    return m_navigatorTreeViewHandle;
}

BOOL CALLBACK ScriptCaller::staticEnumChildWindowCallback(HWND hwnd, LPARAM lparam)
{
    return reinterpret_cast<ScriptCaller*>(lparam)->enumChildWindowCallback(hwnd);
}

BOOL ScriptCaller::enumChildWindowCallback(HWND hwnd)
{
    wchar_t windowCaption[128];
    GetWindowTextW(hwnd, windowCaption, sizeof(windowCaption));

    wchar_t windowClass[1024];
    GetClassNameW(hwnd, windowClass, sizeof(windowClass));

    std::wstringstream msg;

    msg << std::hex
        << L"enumChildWindowCallback: "
        << L"hwnd = 0x" << hwnd
        << L", caption = " << windowCaption
        << L", class = " << windowClass;

    OutputDebugStringW(msg.str().c_str());

    if (wcscmp(windowClass, NAVIGATOR_WINDOW_CLASS_NAME) == 0) {
        m_navigatorTreeViewHandle = hwnd;
        return FALSE;
    }

    return TRUE;
}

int ScriptCaller::findScriptOrdinal(const wchar_t* scriptName)
{
    HTREEITEM root = TreeView_GetRoot(m_navigatorTreeViewHandle);
    if (!root) {
        return 0;
    }

    HTREEITEM child = TreeView_GetChild(m_navigatorTreeViewHandle, root);
    if (!child) {
        return 0;
    }

    // moves to Scripts node
    for (int i = 0; i < 4; i++) {
        child = TreeView_GetNextSibling(m_navigatorTreeViewHandle, child);
        if (!child) {
            return 0;
        }
    }

    // get child node of Scripts
    child = TreeView_GetChild(m_navigatorTreeViewHandle, child);
    if (!child) {
        return 0;
    }

    int ordinal = 0;
    bool found = findScriptOrdinal(scriptName, child, ordinal);
    if (found) {
        return ordinal;
    }
    else {
        return 0;
    }
}

bool ScriptCaller::findScriptOrdinal(const wchar_t* scriptName, HTREEITEM node, int& ordinal)
{
    TVITEMEXW item;
    wchar_t itemName[128];
    item.mask = TVIF_HANDLE | TVIF_TEXT | TVIF_CHILDREN | TVIF_PARAM;
    item.cchTextMax = sizeof(itemName);
    item.pszText = itemName;

    HTREEITEM itemNode = node;
    int i = 0;
    int count = 0;
    bool retval = false;
    std::wstringstream msg;

    while (true) {
        if (i > 0) {
            itemNode = TreeView_GetNextSibling(m_navigatorTreeViewHandle, itemNode);
            if (!itemNode) {
                break;
            }
        }

        item.hItem = itemNode;
        if (TreeView_GetItem(m_navigatorTreeViewHandle, &item)) {
            msg.str(L"");
            msg << L"GetItem: text = " << item.pszText
                << L", nChildren = " << item.cChildren
                << L", lParam = " << item.lParam
                << L", i = " << i
                << L", count = " << count
                << L", ordinal = " << count + ordinal;

            OutputDebugStringW(msg.str().c_str());

            if (item.cChildren > 0) {
                HTREEITEM childNode = TreeView_GetChild(m_navigatorTreeViewHandle, itemNode);
                if (childNode) {
                    bool foundInRecurse = findScriptOrdinal(scriptName, childNode, ordinal);
                    if (foundInRecurse) {
                        retval = true;
                        break;
                    }
                }
            }
            else {
                count += 1;

                if (wcscmp(item.pszText, scriptName) == 0) {
                    retval = true;
                    break;
                }
            }

            i += 1;
        }
        else {
            break;
        }
    }

    ordinal += count;
    return retval;
}
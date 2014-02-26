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
    findNavigatorTreeView();
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
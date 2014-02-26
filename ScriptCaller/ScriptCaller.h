#pragma once

#include <CommCtrl.h>

// --------------------------------------------------
// class definition

class ScriptCaller
{
public:
    ScriptCaller(HWND chartWindowHandle);
    void setDebugLevel(int level);
    bool callScript(const wchar_t* scriptName);

private:
    static const wchar_t* NAVIGATOR_WINDOW_CLASS_NAME;
    static const wchar_t* MT4_INTERNAL_MESSAGE;
    static const UINT MT4_WPARAM_START_SCRIPT;

    int m_debugLevel;

    UINT m_mt4InternalMessage;

    HWND m_chartWindowHandle;
    HWND m_rootWindowHandle;
    HWND m_navigatorTreeViewHandle;

    bool isDebug(int level);

    static BOOL CALLBACK staticEnumChildWindowCallback(HWND hwnd, LPARAM lparam);
    BOOL enumChildWindowCallback(HWND hwnd);

    HWND getRootWindowHandle();
    HWND findNavigatorTreeView();
    int findScriptOrdinal(const wchar_t* scriptName);
    bool findScriptOrdinal(const wchar_t* scriptName, HTREEITEM node, int& ordinal);
    void callScript(int ordinal);
};

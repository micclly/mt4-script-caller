#pragma once

// --------------------------------------------------
// class definition

class ScriptCaller
{
public:
    ScriptCaller(HWND chartWindowHandle);
    bool callScript(const wchar_t* scriptName);

private:
    static const wchar_t* NAVIGATOR_WINDOW_CLASS_NAME;

    HWND m_chartWindowHandle;
    HWND m_rootWindowHandle;
    HWND m_navigatorTreeViewHandle;

    static BOOL CALLBACK staticEnumChildWindowCallback(HWND hwnd, LPARAM lparam);
    BOOL enumChildWindowCallback(HWND hwnd);

    HWND getRootWindowHandle();
    HWND findNavigatorTreeView();
};

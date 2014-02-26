#pragma once

// --------------------------------------------------
// class definition

class ScriptCaller
{
public:
    ScriptCaller(HWND chartWindowHandle);
    bool callScript(const wchar_t* scriptName);

private:
    HWND m_chartWindowHandle;
    HWND m_treeViewHandle;

    HWND findNavigatorTreeView();
};

#include "stdafx.h"
#include "ScriptCaller.h"

// --------------------------------------------------
// public members

ScriptCaller::ScriptCaller(HWND chartWindowHandle)
: m_chartWindowHandle(chartWindowHandle),
    m_treeViewHandle(NULL)
{

}

// --------------------------------------------------
// private members

bool ScriptCaller::callScript(const wchar_t* scriptName)
{
    return true;
}
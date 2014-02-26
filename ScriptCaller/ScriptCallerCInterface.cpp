#include "stdafx.h"
#include "ScriptCaller.h"
#include "ScriptCallerCInterface.h"

// --------------------------------------------------
// C interfaces

static ScriptCaller* cast(long classHandle)
{
    return reinterpret_cast<ScriptCaller*>(classHandle);
}

SCRIPTCALLER_API long ScriptCaller_create(HWND chartWindowHandle)
{
    return reinterpret_cast<long>(new ScriptCaller(chartWindowHandle));
}

SCRIPTCALLER_API void ScriptCaller_setDebugLevel(long classHandle, int level)
{
    return cast(classHandle)->setDebugLevel(level);
}

SCRIPTCALLER_API BOOL ScriptCaller_callScript(long classHandle, const wchar_t* scriptName)
{
    return cast(classHandle)->callScript(scriptName);
}

SCRIPTCALLER_API BOOL ScriptCaller_callScript2(long classHandle, const wchar_t* scriptName, BOOL closeConfigDialog)
{
    bool close = closeConfigDialog ? true : false;
    return cast(classHandle)->callScript(scriptName, close);
}

SCRIPTCALLER_API void ScriptCaller_destroy(long classHandle)
{
    delete cast(classHandle);
}

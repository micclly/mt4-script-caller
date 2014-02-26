#include "stdafx.h"
#include "ScriptCaller.h"
#include "ScriptCallerCInterface.h"

// --------------------------------------------------
// C interfaces

static ScriptCaller* cast(int handle)
{
    return reinterpret_cast<ScriptCaller*>(handle);
}

SCRIPTCALLER_API long ScriptCaller_create()
{
    return reinterpret_cast<long>(new ScriptCaller());
}

SCRIPTCALLER_API BOOL ScriptCaller_callScript(int handle, const wchar_t* scriptName)
{
    return cast(handle)->callScript(scriptName);
}

SCRIPTCALLER_API void ScriptCaller_destroy(long handle)
{
    delete reinterpret_cast<ScriptCaller*>(handle);
}

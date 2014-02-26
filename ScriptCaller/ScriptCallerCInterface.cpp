#include "stdafx.h"
#include "ScriptCaller.h"
#include "ScriptCallerCInterface.h"

// --------------------------------------------------
// C interfaces

SCRIPTCALLER_API long ScriptCaller_create()
{
    return reinterpret_cast<long>(new ScriptCaller());
}

SCRIPTCALLER_API void ScriptCaller_destroy(long handle)
{
    delete reinterpret_cast<ScriptCaller*>(handle);
}

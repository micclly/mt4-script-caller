#pragma once

#ifdef SCRIPTCALLER_EXPORTS
#define SCRIPTCALLER_API extern "C" __declspec(dllexport)
#else
#define SCRIPTCALLER_API extern "C" __declspec(dllimport)
#endif

// --------------------------------------------------
// C interface prototypes

SCRIPTCALLER_API long ScriptCaller_create();
SCRIPTCALLER_API void ScriptCaller_destroy(long handle);
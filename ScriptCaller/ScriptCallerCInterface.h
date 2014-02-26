#pragma once

#ifdef SCRIPTCALLER_EXPORTS
#define SCRIPTCALLER_API extern "C" __declspec(dllexport)
#else
#define SCRIPTCALLER_API extern "C" __declspec(dllimport)
#endif

// --------------------------------------------------
// C interface prototypes

SCRIPTCALLER_API long ScriptCaller_create(HWND chartWindowHandle);
SCRIPTCALLER_API BOOL ScriptCaller_callScript(long classHandle, const wchar_t* scriptName);
SCRIPTCALLER_API void ScriptCaller_destroy(long classHandle);
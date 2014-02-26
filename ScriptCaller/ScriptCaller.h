#ifdef SCRIPTCALLER_EXPORTS
#define SCRIPTCALLER_API extern "C" __declspec(dllexport)
#else
#define SCRIPTCALLER_API extern "C" __declspec(dllimport)
#endif

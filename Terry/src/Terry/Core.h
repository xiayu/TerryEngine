#pragma once
#ifdef TR_PLATFORM_WINDOW
	#ifdef TR_BUILD_DLL
		#define TR_API _declspec(dllexport)
	#else
		#define TR_API _declspec(dllimport)
	#endif
#else
	#error only suport windows now
#endif

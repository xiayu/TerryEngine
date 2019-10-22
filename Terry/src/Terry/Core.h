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


#ifdef TR_ENABLE_ASSERTS
	#define TR_ASSERT(x, ...) { if(!(x)) {TR_ERROR("Assertion Failed:{0}", __VA_ARGS__);__debugbreak();}}
	#define TR_CORE_ASSERT(x, ...) { if(!(x)) {TR_CORE_ERROR("Assertion Failed:{0}", __VA_ARGS__);__debugbreak();}}
#endif // TR_ENABLE_ASSERTS
	#define TR_ASSERT(x, ...)
	#define TR_CORE_ASSERT(x, ...)
#define BIT(x) (1<<x)
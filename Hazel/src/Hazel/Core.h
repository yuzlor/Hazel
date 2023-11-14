#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef  HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport) 
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif //  HZ_BUILD_DLL
#else
	#error Hazel only supports Windows
#endif // HZ_PLATFORM_WINDOWS

#ifdef HZ_ENABLE_ASSERTS
#define HAZEL_ASSERT(x, ...) if(!x) {HZ_ERROR("Assertion Failed At: {0}", __VA_ARGS__);\
	__debugbreak();}
#define HAZEL_CORE_ASSERT(x, ...) if(!x) {HZ_CORE_ERROR("Assertion Failed At: {0}", __VA_ARGS__);\
	__debugbreak();}
#else
#define HAZEL_ASSERT(x, ...)
#define HAZEL_CORE_ASSERT(x, ...)
#endif


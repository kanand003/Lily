#pragma once

#ifdef LY_PLATFORM_WINDOWS
	#ifdef LY_BUILD_DLL
		#define LILY_API _declspec(dllexport)
	#else
		#define LILY_API _declspec(dllimport)
	#endif
#else
	#error Lily only supports Windows Platform
#endif // LY_BUILD_DLL

#ifdef LY_DEBUG
#define LY_ENABLE_ASSERTS
#endif

#if LY_ENABLE_ASSSERTS
	#define LY_ASSERT(x, ...) { if(!(x)) { LY_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LY_CORE_ASSERT(x, ...) { if(!(x)) { LY_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LY_ASSERT(x, ...)
	#define LY_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)

#define LY_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
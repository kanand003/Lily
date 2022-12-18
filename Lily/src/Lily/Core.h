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

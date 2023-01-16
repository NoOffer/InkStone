#pragma once

#ifdef INKS_PLATFORM_WINDOWS
	#ifdef INKS_BUILD_DLL
		#define INKS_API __declspec(dllexport)
	#else
		#define INKS_API __declspec(dllimport)
	#endif // INKS_BUILD_DLL
#else
	#error Unsupported platform (InkStone supports Windows only)
#endif // INKS_PLATFORM_WINDOWS

#ifdef INKS_ENABLE_ASSERTS
#define INKS_ASSERT(x) { if(!(x)) { INKS_ERROR("Assertion failed"); __debugbreak(); } }
#else
#define INKS_ASSERT(x)
#endif // INKS_ENABLE_ASSERTS


#define BIT(x) (1 << x)

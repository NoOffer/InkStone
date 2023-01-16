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

#define BIT(x) (1 << x)

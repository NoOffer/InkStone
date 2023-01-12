#pragma once

#ifdef INKSTONE_PLATFORM_WINDOWS
	#ifdef INKSTONE_BUILD_DLL
		#define INKSTONE_API __declspec(dllexport)
	#else
		#define INKSTONE_API __declspec(dllimport)
	#endif // INKSTONE_BUILD_DLL
#else
	#error Unsupported platform (InkStone supports Windows only)
#endif // INKSTONE_PLATFORM_WINDOWS

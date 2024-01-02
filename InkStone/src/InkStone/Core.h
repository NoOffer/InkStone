#pragma once

#ifdef NXTN_PLATFORM_WINDOWS
#ifdef NXTN_BUILD_DLL
#define NXTN_API __declspec(dllexport)
#else
#define NXTN_API __declspec(dllimport)
#endif // NXTN_BUILD_DLL
#else
#error Platform Not Supported
#endif // NXTN_PLATFORM_WINDOWS

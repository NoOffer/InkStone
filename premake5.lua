workspace "InkStone"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distrib"
	}

outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"

include "InkStone/vendor/GLFW"

project "InkStone"
	location "InkStone"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	pchheader "inks_pch.h"
	pchsource "InkStone/src/inks_pch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{prj.name}/vendor/GLFW/include"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"INKS_PLATFORM_WINDOWS",
			"INKS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "INKS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "INKS_RELEASE"
		optimize "On"

	filter "configurations:Distrib"
		defines "INKS_DISTRIB"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"InkStone/vendor/spdlog/include",
		"InkStone/src"
	}

	links
	{
		"InkStone"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"INKS_PLATFORM_WINDOWS",
		}
		
	filter "configurations:Debug"
		defines "INKS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "INKS_RELEASE"
		optimize "On"

	filter "configurations:Distrib"
		defines "INKS_DISTRIB"
		optimize "On"
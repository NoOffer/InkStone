workspace "InkStone"
	architecture "x64"

	configurations{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.architecture}/%{cfg.buildcfg}"

project "InkStone"
	location "InkStone"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/%{prj.name}/" .. outputdir)
	objdir ("bin-obj/%{prj.name}/" .. outputdir)

	pchheader "pch.h"
	pchsource "%{prj.name}/src/pch.cpp"

	files{
		"%{prj.name}/%{prj.name}.h",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	syslibdirs{
		"%{prj.name}/include/GLFW/lib"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/include/GLFW/include"
	}

	links{
		"opengl32.lib",
		"glfw3.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		staticruntime "off"
		runtime "Release"

		defines{
			"NXTN_PLATFORM_WINDOWS",
			"NXTN_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/Sandbox/" .. outputdir)
		}

	filter "configurations:Debug"
		defines "NXTN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NXTN_RELEASE"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/%{prj.name}/" .. outputdir)
	objdir ("bin-obj/%{prj.name}/" .. outputdir)

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"InkStone"
	}

	links{
		"InkStone"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"NXTN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NXTN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NXTN_RELEASE"
		optimize "On"
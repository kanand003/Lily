workspace "Lily"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include Directories relative to root folder(solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Lily/vendor/GLFW/include"
IncludeDir["Glad"] = "Lily/vendor/Glad/include"
IncludeDir["imgui"] = "Lily/vendor/imgui/include"

include "Lily/vendor/GLFW"
include "Lily/vendor/Glad"
include "Lily/vendor/imgui"

project "Lily"
	location "Lily"
	kind "SharedLib"
	language"C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Lily/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"imgui",
		"opengl32.lib"
	}

	filter	"system:windows"
	
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"LY_PLATFORM_WINDOWS",
			"LY_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	filter "configurations:Debug"
		defines "LY_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	filter "configurations:Release"
		defines "LY_RELEASE"
		buildoptions "/MD"
		optimize "On"
	filter "configurations:Dist"
		defines "LY_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language"C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"Lily/vendor/spdlog/include",
		"Lily/src"
	}
	links
	{
		"Lily"
	}
	filter	"system:windows"
	
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"LY_PLATFORM_WINDOWS"
		}
		filter "configurations:Debug"
			defines "LY_DEBUG"
			buildoptions "/MDd"
			symbols "On"
		filter "configurations:Release"
			defines "LY_RELEASE"
			buildoptions "/MD"
			optimize "On"
		filter "configurations:Dist"
			defines "LY_DIST"
			buildoptions "/MD"
			optimize "On"
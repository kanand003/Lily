workspace "Lily"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Production",
	}

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lily"
	location "Lily"
	kind "SharedLib"
	language"C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	targetdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	include
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	filter	"system:windows"
	
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"LY_PLATFORM_WINDOWS",
			"LY_BUILD_DLL"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	filter "configurations:Debug"
		defines "LY_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "LY_RELEASE"
		optimize "On"
	filter "configurations:Production"
		defines "LY_PRODUCTION"
		optimize "On"
		
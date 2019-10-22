workspace "Terry"
	architecture "x64"
	startproject "SanBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}
--            {Debug\Release\Dist}-{windows\mac\linux}-{x64}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Terry/vendor/glfw/include"

include "Terry/vendor/glfw"

project "Terry"
	location "Terry"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "trpch.h"
	pchsource "Terry/src/trpch.cpp"

	files
	{
		-- ** represent recursive search
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	defines
	{

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++14"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOW",
			"TR_BUILD_DLL",
			"TR_ENABLE_ASSERTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SanBox")
		}
		
	filter "configurations:Debug"
		defines "TR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TR_DIST"
		optimize "On"

project "SanBox"
	location "SanBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		-- ** represent recursive search
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Terry/vendor/spdlog/include",
		"Terry/src",
	}

	links
	{
		"Terry"
	}

	filter "system:windows"
		cppdialect "c++14"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOW",
			"TR_ENABLE_ASSERTS"
		}

	filter "configurations:Debug"
		defines "TR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TR_DIST"
		optimize "On"


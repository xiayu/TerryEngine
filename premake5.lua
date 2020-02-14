-- vs solution name
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
IncludeDir["GLAD"] = "Terry/vendor/glad/include"
IncludeDir["IMGUI"] = "Terry/vendor/imgui"
IncludeDir["GLM"] = "Terry/vendor/glm"

-- include other premake file
include "Terry/vendor/glfw"
include "Terry/vendor/glad"
include "Terry/vendor/imgui"

-- vs project name
project "Terry"
	location "Terry"
	kind "SharedLib" -- DLL
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")  -- outputdir
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 

	pchheader "trpch.h"
	pchsource "Terry/src/trpch.cpp"

	files
	{
		-- ** represent recursive search
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.IMGUI}",
		"%{IncludeDir.GLM}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOW",
			"TR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sanbox/\"")
		}
		
	filter "configurations:Debug"
		defines "TR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TR_DIST"
		runtime "Release"
		optimize "On"

project "SanBox"
	location "SanBox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"

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
		cppdialect "c++17"
		systemversion "latest"

		defines
		{
			"TR_PLATFORM_WINDOW",
		}

	filter "configurations:Debug"
		defines "TR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TR_DIST"
		runtime "Release"
		optimize "On"


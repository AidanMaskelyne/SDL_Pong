workspace "SDL_Pong"
	architecture "x86_64"
	configurations { "Debug", "Release" }

project "pong"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir "target/%{cfg.buildcfg}"
	objdir "target/%{cfg.buildcfg}/obj"

	files {
		"src/**.h",
		"src/**.cpp",
	}

	filter "system:linux"
		links { "SDL2" }

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"

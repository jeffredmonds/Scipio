workspace "Scipio"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Scipio/vendor/GLFW/include"
IncludeDir["Glad"] = "Scipio/vendor/Glad/include"
IncludeDir["ImGui"] = "Scipio/vendor/imgui"

include "Scipio/vendor/GLFW"
include "Scipio/vendor/Glad"
include "Scipio/vendor/imgui"


project "Scipio"
  location "Scipio"
  kind "SharedLib"
  language "C++"
  staticruntime "off"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "ScipioPrecompiledHeader.h"
  pchsource "Scipio/src/ScipioPrecompiledHeader.cpp"

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
    "%{IncludeDir.ImGui}"

  }

  links
  {
    "GLFW",
    "Glad",
    "ImGui",
    "opengl32.lib",
    "dwmapi.lib"
  }

  filter "system:windows"
    cppdialect"C++20"
    systemversion "latest"

    defines
    {
      "SP_PLATFORM_WINDOWS",
      "SP_BUILD_DLL", 
      "GLFW_INCLUDE_NONE"
    }

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

  filter "configurations:Debug"
    defines "SP_DEBUG"
    runtime "debug"
    symbols "On"

  filter "configurations:Release"
    defines "SP_RELEASE"
    runtime "release"
    optimize "On"

  filter "configurations:dist"
    defines "SP_DIST"
    runtime "release"
    optimize "On"

  filter { "action:vs*" }
    buildoptions { "/utf-8" }

project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"
  staticruntime "off"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "Scipio/vendor/spdlog/include",
    "Scipio/src"
  }

  links
  {
    "Scipio"
  }

  filter "system:windows"
    cppdialect"C++20"
    systemversion "latest"

    defines
    {
      "SP_PLATFORM_WINDOWS"
    }

  filter "configurations:Debug"
    defines "SP_DEBUG"
    runtime "debug"
    symbols "On"

  filter "configurations:Release"
    defines "SP_RELEASE"
    runtime "release"
    optimize "On"

  filter "configurations:Dist"
    defines "SP_DIST"
    runtime "release"
    optimize "On"

  filter { "action:vs*" }
    buildoptions { "/utf-8" }
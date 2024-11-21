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
include "Scipio/vendor/GLFW"


project "Scipio"
  location "Scipio"
  kind "SharedLib"
  language "C++"

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
    "%{IncludeDir.GLFW}"
  }

  links
  {
    "GLFW",
    "opengl32.lib",
    "dwmapi.lib"
  }

  filter "system:windows"
    cppdialect"C++20"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "SP_PLATFORM_WINDOWS",
      "SP_BUILD_DLL"
    }

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

  filter "configurations:Debug"
    defines "SP_DEBUG"
    buildoptions "/MDd"
    symbols "On"

  filter "configurations:Release"
    defines "SP_RELEASE"
    buildoptions "/MD"
    optimize "On"

  filter "configurations:dist"
    defines "SP_DIST"
    buildoptions "/MD"
    optimize "On"

  filter { "action:vs*" }
    buildoptions { "/utf-8" }

project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"

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
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "SP_PLATFORM_WINDOWS"
    }

  filter "configurations:Debug"
    defines "SP_DEBUG"
    buildoptions "/MDd"
    symbols "On"

  filter "configurations:Release"
    defines "SP_RELEASE"
    buildoptions "/MD"
    optimize "On"

  filter "configurations:Dist"
    defines "SP_DIST"
    buildoptions "/MD"
    optimize "On"

  filter { "action:vs*" }
    buildoptions { "/utf-8" }
-- premake5.lua

workspace "Hazel"
    architecture "x64"

    configurations 
    { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--使用submodule的premake5.lua文件
include "Hazel/vendor/GLFW"

project "Hazel"
     location "Hazel"
     kind "SharedLib"
     language "C++"
     --staticruntime "off"
     cppdialect "C++17"

     targetdir ("bin/" .. outputdir .. "/%{prj.name}")
     objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
     

     pchheader "hzpch.h"
     pchsource "%{prj.name}/src/hzpch.cpp"

     defines
	{
	    "_CRT_SECURE_NO_WARNINGS", "HZ_BUILD_DLL"
	}

     files 
     { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        --"%{prj.name}/vendor/**.hpp"
     }

     includedirs
     {
          "%{prj.name}/vendor/spdlog/include",
          "%{prj.name}/src",
		  "%{prj.name}/src/Hazel",
          "%{prj.name}/vendor/GLFW/include"
     }

     links {"GLFW", "opengl32.lib"}
   
     filter "system:windows"
          staticruntime "On"
          systemversion "latest"
          
          defines
          {
               "HZ_PLATFORM_WINDOWS",
               "GLFW_INCLUDE_NONE"
          }

          postbuildcommands
          {
               ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
          }

     filter "configurations:Debug"
          defines "HZ_DEBUG"
          buildoptions {"/MDd"} -- 添加buildoptions
          symbols "On"
		  runtime "Debug" -- 运行时链接的dll是debug类型的


     filter "configurations:Release"
          defines "HZ_RELEASE"
          optimize "On"

     filter "configurations:Dist"
          defines "HZ_DIST"
          optimize "On"

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
          "Hazel/vendor/spdlog/include",
          "Hazel/src"
     }

     links
     {
          "Hazel"
     }
     
     filter "system:windows"
          cppdialect "C++17"
          staticruntime "On"
          systemversion "10.0.19041.0"
          
          defines
          {
               "HZ_PLATFORM_WINDOWS"
          }

     filter "configurations:Debug"
          defines "HZ_DEBUG"
          symbols "On"

     filter "configurations:Release"
          defines "HZ_RELEASE"
          optimize "On"

     filter "configurations:Dist"
          defines "HZ_DIST"
          optimize "On"
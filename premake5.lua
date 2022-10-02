workspace "Blackjack"
   configurations { "Debug", "Release" }
   language "C++"
   cppdialect "C++17"

project "Blackjack"
   kind "ConsoleApp"
   targetdir "bin/%{prj.name}/%{cfg.buildcfg}"
   objdir "bin/obj/%{cfg.buildcfg}"

   files { "src/**.hpp", "src/**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"


-- Clean Function --
newaction {
   trigger     = "clean",
   description = "clean the software",
   execute     = function ()
      print("clean the build...")
      os.rmdir("./bin")
      os.rmdir("./build")
      os.execute("rm -r *.xcodeproj")
      os.execute("rm -r *.xcworkspace")
      os.remove("Makefile")
      os.remove("*.make")
      os.remove("**.sln")
      os.remove("**.vcxproj*")
      os.remove("**.cmake")
      os.remove("**CMakeLists.txt")
      print("done.")
   end
}
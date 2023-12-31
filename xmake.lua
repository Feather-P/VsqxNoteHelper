add_rules("mode.debug", "mode.release")

add_requires("pugixml 1.13")
--添加pugixml，指定版本为1.13

target("VsqxNoteHelper")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("pugixml", {public = true})
    --添加pugixml依赖到NoteBlade，并继承到子target

    if is_plat("macosx", "linux") then
        add_cxxflags("-std=c++17")
        add_cxxflags("-DBUILD_PLATFORM=\"$(os)\"")
        add_cxxflags("-DBUILD_TIME=\"$(shell date '+%Y-%m-%dT%H:%M:%S%z')\"")
        add_cxxflags("-DBUILD_HOSTNAME=\"$(shell hostname)\"")
    end
    --Macosx和Linux平台下的编译选项，采用C++17
    if is_plat("windows") then
        add_cxxflags("/std:c++17 /utf-8")
        add_cxxflags("/DBUILD_TIME=\"$(shell powershell Get-Date -Format o)\"")
        add_cxxflags("/DBUILD_HOSTNAME=\"$(env computername)\"")
    end
    --Windows平台下的编译选项，采用C++17


--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--


cmake_minimum_required(VERSION 3.26.0...3.26.3)

include(CMakeUtils/Handy/DisallowInSourceBuilds.cmake) # Comment out to allow
include(CMakeUtils/Handy/SelectCompilerViaFlagIfNotUsingCMakePresets.cmake)  # or else default compiler will be used

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
project(CreateAndUseLibraries VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

include(CMakeUtils/Handy/DisplayGenericInfo.cmake) # Comment out to suppress

#[==================================================[
Build (sub)project(s)
#]==================================================]
add_subdirectory(HeaderLibNeedsCpp14)
add_subdirectory(SharedLibNeedsCpp17)
add_subdirectory(SharedOrStaticLibNeedsCpp17)
add_subdirectory(StaticLibNeedsCpp20)
add_subdirectory(UseCreatedLibsNeedsCpp11)

#[==================================================[
Link executable with libraries
#]==================================================]
target_link_libraries(targetExe 
    PRIVATE 
        targetHeaderLib
        targetSharedLib
        targetSharedOrStaticLib
        targetStaticLib
)

#[==================================================[
Run the executable 
#]==================================================]
add_custom_target(run
    COMMAND ${CMAKE_COMMAND} -E echo "execute: $<TARGET_FILE:targetExe>"
    COMMAND $<TARGET_FILE:targetExe>
)

#[==================================================[
Install targets (libraries and executable) together with
<installation path>/share/cmake/<package name>Config.cmake
which enables easy importing into users' code via cmake find/fetch
#]==================================================]
set(packageName LibrarySuite)

set(targetsToInstall
    targetExe
    targetHeaderLib
    targetSharedLib
    targetSharedOrStaticLib
    targetStaticLib
)

if(BUILD_SHARED_LIBS)
    set(sharedOrStaticType shared)
    message(STATUS "BUILD_SHARED_LIBS: " ${BUILD_SHARED_LIBS} " --- targetSharedOrStaticLib will be built as SHARED library")
else()
    set(sharedOrStaticType static)
    message(STATUS "BUILD_SHARED_LIBS: " ${BUILD_SHARED_LIBS} " --- targetSharedOrStaticLib will be built as STATIC library")
endif()

# Needed to enable switching between install/**/static and install/**/shared
unset(CMAKE_INSTALL_PREFIX CACHE)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # CMAKE_INSTALL_PREFIX was not passed as a commandline argument, therefore set it here:

    set(CMAKE_INSTALL_PREFIX 
        ${CMAKE_BINARY_DIR}/install/${packageName}${PROJECT_VERSION}/${sharedOrStaticType}
        # C:/Packages/${packageName}${PROJECT_VERSION}/${sharedOrStaticType}
        # CACHE PATH "Installation path" FORCE
    )

endif()

message(STATUS "CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT: ${CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT}")
message(STATUS "CMAKE_INSTALL_PREFIX: " ${CMAKE_INSTALL_PREFIX})

include(GNUInstallDirs) # do NOT comment out!
include(CMakeUtils/Package/InstallPackage.cmake)
InstallPackage(${packageName} targetsToInstall)

#[==================================================[
(Optional) IDE solution name
Must be after all other projects since last project(...) is used as solution name
#]==================================================]
if (CMAKE_GENERATOR MATCHES "Visual Studio" OR  # any VS generator
    CMAKE_GENERATOR MATCHES "Eclipse CDT4")     # any Eclipse generator

    project(CreateAndUseLibrariesWithConfigCMake)

endif()

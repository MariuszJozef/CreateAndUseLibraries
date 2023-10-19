#[==================================================[
StaticLib
#]==================================================]
add_library(targetStaticLib STATIC)

target_include_directories(targetStaticLib
    PRIVATE
        hdr
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

#[=========================[
N.B. 
Public headers are:
-- header files which need to be explicitly included by another application/library
-- header files which are included in the aforementioned header files.
Private header are:
-- header files which are only included in source (*.cpp, *.c) files but not in any of the public header files
-- header files included in other private header files
]=========================]

target_sources(targetStaticLib
    PRIVATE
        hdr/StaticLibPrivate.hpp
        src/StaticLibPrivate.cpp
        src/StaticLibApi.cpp
    PUBLIC 
        FILE_SET HEADERS 
        BASE_DIRS ${CMAKE_SOURCE_DIR}/StaticLibNeedsCpp20/include
        FILES 
            ${CMAKE_CURRENT_SOURCE_DIR}/include/StaticLibApi.hpp
)

set_target_properties(targetStaticLib
    PROPERTIES
        OUTPUT_NAME                         StaticLibrary
        EXPORT_NAME                         StaticLib
        DEBUG_POSTFIX                       "_d"
        LIBRARY_OUTPUT_DIRECTORY            ${CMAKE_BINARY_DIR}/buildOut/StaticLibNeedsCpp20/lib/$<CONFIG>
        ARCHIVE_OUTPUT_DIRECTORY            ${CMAKE_BINARY_DIR}/buildOut/StaticLibNeedsCpp20/lib/$<CONFIG>
        LIBRARY_OUTPUT_DIRECTORY_<Config>   ${LIBRARY_OUTPUT_DIRECTORY}
        ARCHIVE_OUTPUT_DIRECTORY_<Config>   ${ARCHIVE_OUTPUT_DIRECTORY}
)

target_compile_features(targetStaticLib
    PUBLIC
        cxx_std_20
)

if(MSVC)

    target_compile_options(targetStaticLib 
        PRIVATE
            /EHsc
            /W2
            # /Wall
    )

else()

    target_compile_options(targetStaticLib 
        PRIVATE
            -Wall
            # -Wextra
            # -Wpedantic
    )

endif()

#[==================================================[
HeaderLib
#]==================================================]
add_library(targetHeaderLib INTERFACE)

target_include_directories(targetHeaderLib
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources(targetHeaderLib
    INTERFACE
        FILE_SET HEADERS 
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES 
            ${CMAKE_CURRENT_SOURCE_DIR}/include/HeaderLibApi.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/HeaderLib.hpp
)

set_target_properties(targetHeaderLib
    PROPERTIES
        EXPORT_NAME HeaderLib
)

target_compile_features(targetHeaderLib
    INTERFACE
        cxx_std_14
)

if(MSVC)

    target_compile_options(targetHeaderLib 
        INTERFACE
            /EHsc
            /W2
            # /Wall
    )

else()

    target_compile_options(targetHeaderLib 
        INTERFACE
            -Wall
            # -Wextra
            # -Wpedantic
    )

endif()

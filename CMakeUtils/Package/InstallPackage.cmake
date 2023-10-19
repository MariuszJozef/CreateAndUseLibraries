#[==================================================[
Install library targets as a package
N.B. Ensure that the name of the file: 
        CMakeUtils/Package/<packageName>Config.cmake.in
    begins with the packageName selected below
#]==================================================]
function(InstallPackage packageName targetList)

    install(TARGETS ${${targetList}}
        EXPORT ${packageName}
            RUNTIME         DESTINATION ${CMAKE_INSTALL_BINDIR}/$<CONFIG>
            LIBRARY         DESTINATION ${CMAKE_INSTALL_LIBDIR}/$<CONFIG>
            ARCHIVE         DESTINATION ${CMAKE_INSTALL_LIBDIR}/$<CONFIG>
            FILE_SET        HEADERS
            INCLUDES        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    install(EXPORT ${packageName}
        FILE ${packageName}Targets.cmake
        NAMESPACE ${packageName}::
        DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake
    )

    include(CMakePackageConfigHelpers)

    configure_package_config_file(
        CMakeUtils/Package/${packageName}Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${packageName}Config.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake
    )

    write_basic_package_version_file(${packageName}ConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
        # COMPATIBILITY SameMajorVersion
        # COMPATIBILITY ExactVersion
    )

    install(
        FILES 
            ${CMAKE_CURRENT_BINARY_DIR}/${packageName}Config.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/${packageName}ConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake
    )

endfunction()

cmake_minimum_required(VERSION 3.0)
include ( GNUInstallDirs )
set(VERSION "0.4.7")

project(kytea LANGUAGES CXX VERSION ${VERSION})

set(INSTALL_BIN_DIR "${CMAKE_INSTALL_BINDIR}"     CACHE PATH "Installation directory for executables")
set(INSTALL_LIB_DIR "${CMAKE_INSTALL_LIBDIR}"     CACHE PATH "Installation directory for libraries")
set(INSTALL_INC_DIR "${CMAKE_INSTALL_INCLUDEDIR}" CACHE PATH "Installation directory for headers")
set(INSTALL_MAN_DIR "${CMAKE_INSTALL_MANDIR}"     CACHE PATH "Installation directory for manual pages")
set(INSTALL_PKGCONFIG_DIR "${CMAKE_INSTALL_DATADIR}/pkgconfig" CACHE PATH "Installation directory for pkgconfig (.pc) files")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)

if(MSVC)
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

   add_definitions(
       -D_CRT_SECURE_NO_DEPRECATE
       -D_CRT_NONSTDC_NO_DEPRECATE
       -DNOMINMAX)

endif()

include(CMakePackageConfigHelpers)

set(INSTALL_CMAKECFG_DIR "lib/cmake/${PROJECT_NAME}")
set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(VERSION_CONFIG "${GENERATED_DIR}/${PROJECT_NAME}ConfigVersion.cmake")
set(PROJECT_CONFIG "${GENERATED_DIR}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(NAMESPACE "${PROJECT_NAME}::")

write_basic_package_version_file(
   "${VERSION_CONFIG}" COMPATIBILITY SameMajorVersion)

configure_package_config_file(
   "cmake/Config.cmake.in"
   "${PROJECT_CONFIG}"
   INSTALL_DESTINATION "${INSTALL_CMAKECFG_DIR}"
   PATH_VARS INSTALL_INC_DIR)

install(
   FILES "${PROJECT_CONFIG}" "${VERSION_CONFIG}"
   DESTINATION "${INSTALL_CMAKECFG_DIR}")

install(
   EXPORT "${TARGETS_EXPORT_NAME}"
   NAMESPACE "${NAMESPACE}"
   DESTINATION "${INSTALL_CMAKECFG_DIR}")

install(
    DIRECTORY "src/include/kytea/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/kytea")

add_definitions(-DPKGDATADIR=".")
add_subdirectory(src)
add_subdirectory(data)


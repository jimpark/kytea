set(LIB_NAME kytealib)
set(STATIC_LIB_NAME ${LIB_NAME}-static)
set(SHARED_LIB_NAME ${LIB_NAME})

project(kytealib LANGUAGES CXX VERSION ${VERSION})

add_subdirectory(liblinear)
include_directories("../include/kytea")

set(SOURCE
    corpus-io-eda.cpp
    corpus-io-full.cpp
    corpus-io-part.cpp
    corpus-io-prob.cpp
    corpus-io-raw.cpp
    corpus-io-tokenized.cpp
    corpus-io.cpp
    dictionary.cpp
    feature-io.cpp
    feature-lookup.cpp
    general-io.cpp
    kytea-config.cpp
    kytea-lm.cpp
    kytea-model.cpp
    kytea-string.cpp
    kytea-struct.cpp
    kytea-util.cpp
    kytea.cpp
    model-io.cpp
    string-util.cpp)

add_library(${STATIC_LIB_NAME} STATIC "\$<TARGET_OBJECTS:liblinear>" ${SOURCE})
add_library(${SHARED_LIB_NAME} SHARED "\$<TARGET_OBJECTS:liblinear>" ${SOURCE})

target_compile_definitions(${SHARED_LIB_NAME}
    PRIVATE "KYTEA_DLL_EXPORTS"
    PUBLIC "KYTEA_DLL")

if(MSVC)
   set_target_properties(${STATIC_LIB_NAME} PROPERTIES
      COMPILE_FLAGS "/Fd\"${CMAKE_CURRENT_BINARY_DIR}/${STATIC_LIB_NAME}.pdb\"")

   set_target_properties(${SHARED_LIB_NAME} PROPERTIES
      LINK_FLAGS "/PDB:\"${CMAKE_CURRENT_BINARY_DIR}/${SHARED_LIB_NAME}.pdb\"")

   install(
      FILES ${CMAKE_CURRENT_BINARY_DIR}/${STATIC_LIB_NAME}.pdb
            ${CMAKE_CURRENT_BINARY_DIR}/${SHARED_LIB_NAME}.pdb
      DESTINATION ${CMAKE_INSTALL_LIBDIR}
      CONFIGURATIONS Debug)
endif()

install(TARGETS ${STATIC_LIB_NAME} ${SHARED_LIB_NAME}
   EXPORT "${TARGETS_EXPORT_NAME}"
   RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
   ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
   LIBRARY DESTINATION "${INSTALL_LIB_DIR}" )


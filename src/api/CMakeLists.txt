project(kytea-api LANGUAGES CXX)

set(SOURCE
    api-example.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} kytealib-static)

install(TARGETS kytea-api
   RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
   ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
   LIBRARY DESTINATION "${INSTALL_LIB_DIR}")

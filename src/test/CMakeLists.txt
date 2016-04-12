project(kytea-test LANGUAGES CXX)

add_executable(${PROJECT_NAME} test-kytea.cpp)
target_link_libraries(${PROJECT_NAME} kytealib-static)

install(TARGETS kytea-test
   RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
   ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
   LIBRARY DESTINATION "${INSTALL_LIB_DIR}")

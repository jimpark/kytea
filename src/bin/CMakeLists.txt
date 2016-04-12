project(kytea-bin LANGUAGES CXX)

add_executable(run-kytea run-kytea.cpp)
target_link_libraries(run-kytea kytealib-static)

add_executable(train-kytea train-kytea.cpp)
target_link_libraries(train-kytea kytealib-static)

install(TARGETS run-kytea train-kytea
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")

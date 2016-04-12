project(model)

install(CODE "execute_process(COMMAND gzip -dc ${CMAKE_CURRENT_SOURCE_DIR}/model.bin.gz OUTPUT_FILE data/model.bin)")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/model.bin DESTINATION ${CMAKE_INSTALL_BINDIR})

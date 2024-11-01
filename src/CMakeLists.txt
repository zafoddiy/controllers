# src/CMakeLists.txt
add_executable(server_exe server.c)
add_executable(drive drive.c)
add_executable(powerpack powerpack.c)
add_executable(cooling cooling.c)
target_link_libraries(server_exe server shared)
target_link_libraries(drive controllers shared)
target_link_libraries(powerpack controllers shared)
target_link_libraries(cooling controllers shared)
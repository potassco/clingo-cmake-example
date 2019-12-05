add_executable(c-example "c-example.c")
target_link_libraries(c-example PRIVATE libclingo)

add_executable(cc-example "cc-example.cc")
target_link_libraries(cc-example PRIVATE libclingo)

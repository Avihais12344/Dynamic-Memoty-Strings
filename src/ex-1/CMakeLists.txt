add_library(fibonacci "fibonacci.h" "fibonacci.c")
add_executable(ex-1 "main.c" "fibonacci.c")
target_link_libraries(ex-1 PRIVATE fibonacci)
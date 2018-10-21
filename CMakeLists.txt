cmake_minimum_required(VERSION 3.6)
project(fractol)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
include_directories(. libftprintf minilibx_macos) # header directories
link_directories(libftprintf minilibx_macos) # library directories
set(SOURCE_FILES
        main.c init_functions.c iteration_functions.c hooks.c threads.c more_hooks.c) # sources
add_executable(fractol ${SOURCE_FILES}) # compilation
target_link_libraries(fractol -lftprintf  -lmlx "-framework OpenGL" "-framework AppKit") # linkage
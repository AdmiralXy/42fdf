cmake_minimum_required(VERSION 3.19)
project(fdf C)

set(CMAKE_C_STANDARD 99)

include_directories(libft)

include_directories(minilibx-linux)

add_executable(fdf ft_fdf.c ft_parser.c ft_draw.c ft_transforms.c ft_controls.c ft_utils.c)
target_link_libraries(fdf libft)
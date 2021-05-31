INC = /usr/include
INCLIB = $(INC)/minilibx-linux/lib
INCLUDES = ft_fdf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INC) -g -Ilibft

NAME = fdf
SRC = ft_fdf.c ft_parser.c ft_draw.c ft_transforms.c ft_utils.c ft_controls.c
OBJ = $(SRC:%.c=%.o)

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = minilibx_macos
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# MacOS
	LFLAGS = -lmlx -lm -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
else
	# Linux
	LFLAGS = -Lminilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
	CFLAGS += -Iminilibx-linux
endif

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@make -C libft
ifneq ($(UNAME), Darwin)
	@make -C minilibx-linux
endif
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS) libft/libft.a

clean:
ifneq ($(UNAME), Darwin)
	@make -C minilibx-linux clean
endif
	@make -C libft clean
	$(RM) $(OBJ)

fclean: clean
ifneq ($(UNAME), Darwin)
	$(RM) minilibx-linux/libmlx_Linux.a
endif
	@make -C libft fclean
	$(RM) $(NAME)

re: clean all

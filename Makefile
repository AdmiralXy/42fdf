INC = /usr/include
INCLIB = $(INC)/minilibx-linux/lib
INCLUDES = ft_fdf.h

MAC_MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MAC_MINILIBX_DIRECTORY = minilibx_macos
MAC_MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INC) -g -Ilibft

NAME = fdf
SRC = ft_fdf.c ft_parser.c ft_draw.c ft_transforms.c ft_utils.c ft_controls.c
OBJ = $(SRC:%.c=%.o)

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# MacOS
	LFLAGS = -lmlx -lm -L$(MAC_MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
else
	# Linux
	LFLAGS = -Lminilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
	CFLAGS += -Iminilibx-linux
endif

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ)
	@make -C libft
ifneq ($(UNAME), Darwin)
	@make -C minilibx-linux
endif
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS) libft/libft.a

all: $(NAME)

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

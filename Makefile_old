INC = /usr/include
INCLIB = $(INC)/minilibx-linux/lib
INCLUDES = ft_fdf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INC) -O3 -Iminilibx-linux -g -Ilibft

NAME = fdf
SRC = ft_fdf.c ft_parser.c ft_draw.c ft_transforms.c ft_utils.c ft_controls.c
OBJ = $(SRC:%.c=%.o)

LFLAGS = -Lminilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# MacOS
else
	#Linux and others...
	LFLAGS += -lbsd
endif

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@make -C libft
	@make -C minilibx-linux
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS) libft/libft.a

clean:
	@make -C minilibx-linux clean
	@make -C libft clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) minilibx-linux/libmlx_Linux.a
	@make -C libft fclean
	$(RM) $(NAME)

re: clean all

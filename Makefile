INC = /usr/include
INCLIB = $(INC)/minilibx-linux/lib
INCLUDES = ft_fdf.h

MAC_MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MAC_MINILIBX_DIRECTORY = minilibx_macos
MAC_MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INC) -g -Ilibft

NAME = fdf
SRCS = ft_fdf.c ft_parser.c ft_draw.c ft_transforms.c ft_utils.c ft_controls.c ft_draw_text.c
OBJS = $(SRCS:%.c=%.o)

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

$(NAME): $(OBJS)
	@make -C libft
ifneq ($(UNAME), Darwin)
	@make -C minilibx-linux
endif
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS) libft/libft.a

all: $(NAME)

clean:
	@make -C minilibx_macos clean
	@make -C minilibx-linux clean
	@make -C libft clean
	$(RM) ft_fdf.h
	$(RM) $(OBJS)

fclean: clean
	@make -C minilibx_macos clean
	$(RM) minilibx-linux/libmlx_Linux.a
	@make -C libft fclean
	$(RM) $(NAME)

re: clean all

norme:
	norminette $(SRCS) ft_fdf.h
	norminette libft/*.c libft/*.h

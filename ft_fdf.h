#ifndef FT_FDF_H
# define FT_FDF_H

// Libs

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

// Constants
//
//# define WIN_HEIGHT 1280
//# define WIN_WIDTH 720
//# define T_OFFSET 50
//# define T_HEIGHT 17
//# define T_COLOR 0xf00000
//
// Keys
//
//# define KEY_UP 119
//# define KEY_DOWN 115
//# define KEY_LEFT 97
//# define KEY_RIGHT 100
//# define KEY_EXIT 65307
//# define KEY_ROTATE_LEFT 113
//# define KEY_ROTATE_RIGHT 101
//# define KEY_SCALE_PLUS 122
//# define KEY_SCALE_MINUS 120
//# define KEY_HEIGHT_PLUS 102
//# define KEY_HEIGHT_MINUS 103

// Constants

# define WIN_HEIGHT 1280
# define WIN_WIDTH 720
# define T_OFFSET 50
# define T_HEIGHT 17
# define T_COLOR 0xf00000

// Keys

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_EXIT 53
# define KEY_ROTATE_LEFT 12
# define KEY_ROTATE_RIGHT 14
# define KEY_SCALE_PLUS 6
# define KEY_SCALE_MINUS 7
# define KEY_HEIGHT_PLUS 3
# define KEY_HEIGHT_MINUS 5

// Structs

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**map;
	int		elevate;
	int		scale;
	float	angle;
	int		shift_x;
	int		shift_y;
	void	*mlx;
	void	*mlx_win;
}	t_fdf;

// Functions

int		ft_parser(char *file_path, t_fdf *data);
void	ft_draw(t_fdf *data, int init);
int		ft_controls(int keycode, t_fdf *data);
void	ft_transforms(t_point *p1, t_point *p2, t_fdf *data);
void	ft_render_text(t_fdf *data);
void	ft_init_fdf(t_fdf *data);
void	ft_exit(t_fdf *data);

#endif

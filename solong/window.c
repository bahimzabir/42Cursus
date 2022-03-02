#include "mlx.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_event
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		x;
	int		y;
	int		bpp;
	int		slin;
	int		endian;
}	t_event;

int	put_image(t_event *window)
{
	char	*relative_path = "./bg.xpm";
	char	*brick_path = "./brick.xpm";
	int width;
	int height;
	int	i;
	int	j;
	char *map = "1111111111\n1000110001\n10000000000001\n1000110001\n1000110001\n1000100101\n1000010001\n1010000001\n1000000001\n1111111111"; 
	i = 0;
	j = 0;
	window->img = mlx_xpm_file_to_image(window->mlx, relative_path, &width, &height);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	while (*map)
	{
		if(*map == '1')
		{
			window->img = mlx_xpm_file_to_image(window->mlx, brick_path, &width, &height);
			mlx_put_image_to_window(window->mlx, window->win, window->img, i, j);
			i += 50;
		}
		else if(*map == '\n')
		{
			j += 50;
			i = 0;
		}
		else
			i += 50;
		map++;
	}

	return (1);
}


int	main(void)
{
	t_event	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 500, 500, "Window");
	put_image(&window);
	mlx_loop(window.mlx);
}

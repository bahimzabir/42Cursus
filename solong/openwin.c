/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openwin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:48:22 by azabir            #+#    #+#             */
/*   Updated: 2022/02/16 16:48:24 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

typedef struct s_data {
	void	*img;
	void	*win;
	void	*mlx;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght) + x * (data->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

int	loop_hook(int keycode, t_data *event)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	return (0);
}

int	main(void)
{
	t_data	event;
	int		i;

	i = 5;
	event.mlx = mlx_init();
	event.win = mlx_new_window(event.mlx, 3, 3, "MyFirstWindow");
	event.img = mlx_new_image(event.mlx, 3, 3);
	event.addr = mlx_get_data_addr(event.img, &event.bits_per_pixel,
			&event.line_lenght, &event.endian);
	while (i++ < 1000)
		my_mlx_pixel_put(&event, i, i + 1, 0x00FF0000);
	mlx_put_image_to_window(event.mlx, event.win, event.img, 0, 0);
	mlx_loop_hook(event.mlx, loop_hook, &event);
	mlx_loop(event.mlx);
}

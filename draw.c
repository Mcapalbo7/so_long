/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:59:24 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/05/28 17:59:24 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64 + 64);
}

static void	draw_player(t_game *game, void *image, int x, int y)
{
	game -> xp = x;
	game -> yp = y;
	draw_img(game, image, x, y);
}

static void	draw_exit(t_game *game, int x, int y)
{
	if (game->n_collect > 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"images/exit.xpm", &game->img_w, &game->img_h);
	}
	else if (game->n_collect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"images/exit2.xpm", &game->img_w, &game->img_h);
	}
	draw_img(game, game->img_exit, x, y);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][x++])
		{
			if (game->map[y][x] == '0')
				draw_img(game, game->img_bckg, x, y);
			else if (game->map[y][x] == 'C')
				draw_img(game, game->img_colect, x, y);
			else if (game->map[y][x] == 'P')
				draw_player(game, game->img_player, x, y);
			else if (game->map[y][x] == 'E')
				draw_exit(game, x, y);
			else if (game->map[y][x] == 'N')
				draw_img(game, game->img_enemy, x, y);
		}
	}
	if (game->n_collect == -1)
		img_win(game);
	moves(game);
	return (0);
}

void	draw_tomb(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_clear_window(game->mlx, game->win);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"images/tomb.xpm", &game->img_w, &game->img_h);
	game->endgame = 1;
	draw_map(game);
	draw_wall(game);
}

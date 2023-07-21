/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:19:54 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/06/24 20:34:44 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_d(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game->map[game->yp][game->xp - 1] = '0';
	game->moves++;
	game->n_collect = -1;
	game->endgame = 1;
	draw_map(game);
	draw_wall(game);
}

void	win_s(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game->map[game->yp - 1][game->xp] = '0';
	game->moves++;
	game->n_collect = -1;
	game->endgame = 1;
	draw_map(game);
	draw_wall(game);
}

void	win_a(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game->map[game->yp][game->xp + 1] = '0';
	game->moves++;
	game->n_collect = -1;
	game->endgame = 1;
	draw_map(game);
	draw_wall(game);
}

void	win_w(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game->map[game->yp + 1][game-> xp] = '0';
	game->moves++;
	game->n_collect = -1;
	game->endgame = 1;
	draw_map(game);
	draw_wall(game);
}

void	img_win(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->win);
	game->img_end = mlx_xpm_file_to_image
		(game->mlx, "images/win.xpm", &x, &y);
	mlx_put_image_to_window(game->mlx, game->win, game->img_end,
		(((game->map_w) / 2) - 390), (((game->map_h) / 2) - 85));
}

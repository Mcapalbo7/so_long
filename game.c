/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:36:56 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/06/24 21:00:19 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	button(int keycode, t_game *game)
{
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		game->yp -= 1;
		player_w(game);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		game->xp -= 1;
		player_a(game);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		game->yp += 1;
		player_s(game);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		game->xp += 1;
		player_d(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
		button (keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->win, 9, 1L << 21, draw_map, game);
	mlx_hook(game->win, 9, 1L << 21, draw_wall, game);
	mlx_loop_hook(game->mlx, animation, game);
}

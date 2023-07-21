/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:51:53 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/05/28 17:51:53 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 25, 20, 16777215, "moves: ");
	mlx_string_put(game->mlx, game->win, 125, 20, 16777215, str);
	free(str);
}

void	term(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	ft_putstr("moves: ");
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
}

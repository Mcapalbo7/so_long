/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:48:43 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/05/28 17:48:43 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_bckg;
	void	*img_wall;
	void	*img_wall2;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	void	*img_enemy;
	void	*img_end;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		xp;
	int		yp;
	int		moves;
	int		endgame;
	int		loop;
	int		pos_enemy;
}	t_game;

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

int		animation(t_game *game);
int		draw_wall(t_game *game);
void	draw_img(t_game *game, void *img, int x, int y);
int		draw_map(t_game *game);
void	draw_tomb(t_game *game);
void	free_map(char **map);
int		exit_game(t_game *game);
void	gameplay(t_game *game);
void	init_game(t_game *game);
void	moves(t_game *game);
void	term(t_game *game);
int		map_check(t_game *game);
void	player_w(t_game *game);
void	player_a(t_game *game);
void	player_s(t_game *game);
void	player_d(t_game *game);
char	**read_map(char *path);
void	win_d(t_game *game);
void	win_s(t_game *game);
void	win_a(t_game *game);
void	win_w(t_game *game);
void	img_win(t_game *game);

#endif

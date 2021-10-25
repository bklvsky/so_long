/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:32:31 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/24 23:03:21 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static char	*get_en_path(int i)
{
	if (i == 0)
		return (ENEMY_1_TEX_PATH);
	else if (i == 1)
		return (ENEMY_2_TEX_PATH);
	else if (i == 2)
		return (ENEMY_3_TEX_PATH);
	else if (i == 3)
		return (ENEMY_4_TEX_PATH);
	else if (i == 4)
		return (ENEMY_5_TEX_PATH);
	else if (i == 5)
		return (ENEMY_6_TEX_PATH);
}

static int	get_enemy_tex(void *mlx, t_img *enemy)
{
	int		i;
	
	i = 0;
	while (i < ENEMY_ANIMATION)
	{
		enemy[i].img = mlx_xpm_file_to_image(mlx, get_en_path(i), \
								enemy[i].width, enemy[i].height);
		if (!enemy[i].img)
			return (-1);
		i += 1;
	}
	return (0);
}

static char	*get_cllct_path(int i)
{
	if (i == 1)
		return (CLLCT_2_TEX_PATH);
	else
		return (CLLCT_3_TEX_PATH);
}

static int	get_cllct_anim_tex(void *mlx, t_img *cllct)
{
	int		i;

	i = 1;
	while (i < CLLCT_ANIMATION)
	{
		cllct[i].img = mlx_xpm_file_to_image(mlx, get_cllct_path(i), \
										cllct[i].width, cllct[i].height);
		if (!cllct[i].img)
			return (-1);
		i += 1;
	}
	return (0);
}

int	get_animation_tex(t_win *win)
{
	if (get_enemy_tex(win->mlx, win->enemy) < 0 || \
								get_cllct_anim_tex(win->mlx, win->cllct) < 0)
		return (-1);
	return (0);
}

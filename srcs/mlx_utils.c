/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:29:20 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/23 01:40:51 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	color_transparent(unsigned int trgb)
{
	return (!(trgb & (255 << 16)) && !(trgb & (255 << 8)) && !(trgb & 255));
}

void	put_square(t_img *img, t_img tex, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < tex.height && y + i < img->height)
	{
		j = 0;
		while (j < tex.width && x + j < img->width)
		{
			color = *(unsigned int *) \
						(tex.addr + (i * tex.line_len + j * (tex.bpp / 8)));
			if (!color_transparent(color))
				my_pixel_put(img, x + j, y + i, color);
			j += 1;
		}
		i += 1;
	}
}

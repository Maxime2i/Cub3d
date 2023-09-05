/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_and_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:14:44 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/05 20:01:21 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_init_arg(t_info *info, char *dest)
{
	int i;

	i = 0;
	while (dest[i])
	{
		i++;
	}
}

int ft_fill_map_and_arg(t_info *info, char *dest)
{
	int i;

	if (dest && dest[0] == '\0')
	{
		free(dest);
		dest = NULL;
	}
	if (!dest)
		return (print_error_message(ERRCODE_MAP_VOID));
	i = ft_init_arg(info, dest);
	if (i == -1)
		return (-1);
}

int ft_init_map_and_arg(int fd, t_info *info)
{
	int rd;
	char buff[BUFFER_SIZE + 1];
	char *dest;

	rd = 1;
	dest = NULL;
	while (rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		dest = ft_strjoin_free_1(dest, buff);
		if (!dest)
			return (print_error_message(ERRCODE_MALLOC));
	}
	if (rd == -1)
	{
		if (dest)
			free(dest);
		return (print_error_message(ERRCODE_READ));
	}
	return (ft_fill_map_and_arg(info, dest));
}

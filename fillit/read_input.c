/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:18:50 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 17:44:48 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	ft_realign(t_mino **tetriminos)
{
	int	i;
	int	x;
	int	y;
	int	b;

	i = 0;
	while (tetriminos[i] != NULL)
	{
		b = 0;
		x = tetriminos[i]->block[0].x;
		y = tetriminos[i]->block[0].y;
		while (b < 4)
		{
			tetriminos[i]->block[b].x = tetriminos[i]->block[b].x - x;
			tetriminos[i]->block[b].y = tetriminos[i]->block[b].y - y;
			b++;
		}
		i++;
	}
}

static int	ft_save_mino(char *temp, t_mino *tetrimino, int i, int n)
{
	tetrimino->block[n].x = i % 4;
	tetrimino->block[n].y = i / 4;
	if (n == 3)
		return (n);
	if (i + 1 < 16 && (i + 1) % 4 != 0 && temp[i + 1] == '#')
	{
		if (n == 0)
			n = ft_save_mino(temp, tetrimino, i + 1, n + 1);
		else if (n > 0 && (tetrimino->block[n - 1].x != (i + 1) % 4 ||
		tetrimino->block[n - 1].y != (i + 1) / 4))
			n = ft_save_mino(temp, tetrimino, i + 1, n + 1);
	}
	if (n != 3 && i + 4 < 16 && temp[i + 4] == '#')
		n = ft_save_mino(temp, tetrimino, i + 4, n + 1);
	if (n != 3 && i - 1 > 0 && i % 4 != 0 && temp[i - 1] == '#')
	{
		if (n > 0 && (tetrimino->block[n - 1].x != (i - 1) % 4 ||
		tetrimino->block[n - 1].y != (i - 1) / 4) && (n == 1 || (n > 1 &&
		(tetrimino->block[n - 2].x != (i - 1) % 4 ||
		tetrimino->block[n - 2].y != (i - 1) / 4))))
			n = ft_save_mino(temp, tetrimino, i - 1, n + 1);
	}
	return (n);
}

static int	ft_set_mino(char *temp, t_mino **tetrimino, int index)
{
	int		i;
	int		blocks;

	i = 0;
	blocks = 0;
	while (temp[i] == '#' || temp[i] == '.')
	{
		if (temp[i] == '#')
			blocks++;
		i++;
	}
	if (temp[i] != '\0' || blocks != 4)
		return (EXIT_FAILURE);
	if (!(*tetrimino = (t_mino*)malloc(sizeof(t_mino))))
		return (EXIT_FAILURE);
	(*tetrimino)->pos = 'A' + index;
	(*tetrimino)->added = 0;
	i = 0;
	while (temp[i] != '#')
		i++;
	if (ft_save_mino(temp, *tetrimino, i, 0) != 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_get_next_mino(int fd, t_mino **tetrimino, int index)
{
	int		ret;
	int		lines;
	char	temp[16 + 1];
	char	*line;

	lines = 0;
	line = NULL;
	ft_memset(temp, 0, 17);
	while (lines < 4)
	{
		if ((ret = get_next_line(fd, &line)) != 1)
			return (EXIT_FAILURE);
		else if (ft_strlen(line) != 4)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		ft_strcat(temp, line);
		free(line);
		lines++;
	}
	if (ft_set_mino(temp, tetrimino, index) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			ft_read_input(int fd, t_mino **tetriminos, int arr_size)
{
	int		ret;
	int		i;
	char	*line;

	ret = 1;
	i = 0;
	line = NULL;
	while (ret == 1)
	{
		if (ft_get_next_mino(fd, &tetriminos[i], i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
		if (i > arr_size)
			return (EXIT_FAILURE);
		if ((ret = get_next_line(fd, &line)) == 1 && *line != '\0')
		{
			free(line);
			return (EXIT_FAILURE);
		}
		free(line);
	}
	tetriminos[i] = NULL;
	ft_realign(tetriminos);
	return (EXIT_SUCCESS);
}

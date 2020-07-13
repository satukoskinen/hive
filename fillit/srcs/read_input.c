/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:18:50 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/13 22:19:45 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/*
** If an error has been encountered, the array filled up to index i is freed
** and EXIT_FAILURE is returned for ft_read_input to return back to main.
*/

static int	ft_free_and_exit(char **tetriminos, int i)
{
	while (i >= 0)
	{
		free(tetriminos[i]);
		i--;
	}
	return (EXIT_FAILURE);
}

/*
**
*/

static int	ft_check_block_positions(char *mino)
{
	int i;
	int j;
	char pos;
	
	i = 0;
	j = 0;
	pos = 0;
	while (mino[4 * i + j] != '#')
	{
		if (j + 1 == 4)
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	
}

/*
** After a 4x4 square has been saved, ft_check_mino checks
** that it contains a valid Tetrimino.
*/

static int	ft_check_mino(char *mino)
{
	int i;
	int blocks;

	i = 0;
	blocks = 0;
	while (mino[i] == '#' || mino[i] == '.')
	{
		if (mino[i] == '#')
			blocks++;
		i++;
	}
	if (mino[i] != '\0' || blocks != 4)
		return (EXIT_FAILURE);
	if (ft_check_block_positions(mino) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
** 
*/

static int	ft_get_next_mino(int fd, char *temp)
{
	int		ret;
	int		lines;
	char	*line;

	ret = 1;
	lines = 0;
	line = NULL;
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
	if (ft_check_mino(temp) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
** 
*/

int			ft_read_input(int fd, char **tetriminos)
{
	int		ret;
	int		i;
	char	temp[16 + 1];
	char	*line;

	ret = 1;
	i = 0;
	line = NULL;
	while (ret == 1)
	{
		ft_memset(temp, 0, 17);
		if (ft_get_next_mino(fd, temp) == EXIT_FAILURE)
			return (ft_free_and_exit(tetriminos, i - 1));
		tetriminos[i++] = ft_strdup(temp);
		if (i == 26)
			return (ft_free_and_exit(tetriminos, i - 1));
		if ((ret = get_next_line(fd, &line)) == 1 && *line != '\0')
		{
			free(line);
			return (ft_free_and_exit(tetriminos, i - 1));
		}
		free(line);
	}
	tetriminos[i] = 0;
	return (EXIT_SUCCESS);
}

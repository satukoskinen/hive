/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:44:10 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 10:09:24 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_free_and_return(char *line)
{
	free(line);
	return (EXIT_FAILURE);
}

static int	ft_get_dimension(char *line)
{
	int i;
	int dim;

	i = 0;
	dim = 0;
	while (line[i] != '\0')
	{
		while (ft_isspace(line[i]))
			i++;
		if (!(ft_isspace(line[i])) && line[i] != '\0')
			dim++;
		while (!(ft_isspace(line[i])) && line[i] != '\0')
			i++;
	}
	return (dim);
}

static int	***ft_initialize_grid(int n)
{
	int	***sudoku;
	int	i;
	int	j;
	
	sudoku = (int***)malloc(sizeof(int**) * n);
	if (!sudoku)
		return (NULL);
	i = 0;
	while (i < n)
	{
		j = 0;
		sudoku[i] = (int**)malloc(sizeof(int*) * n);
		if (!sudoku[i])
			return (NULL);
		while (j < n)
		{
			sudoku[i][j] = (int*)malloc(sizeof(int) * (n + 1));
			if (!sudoku[i][j])
				return (NULL);
			ft_memset(sudoku[i][j], 0, sizeof(int) * (n + 1));
			j++;
		}
		i++;
	}
	return (sudoku);
}

static int	ft_read_to_grid(int fd, int n, int ***sudoku, char *line)
{
	int i;
	int j;
	int k;
	
	i = 0;
	while (i < n)
	{
		j = 0;
		k = 0;
		while (j < n && line[k] != '\0')
		{
			sudoku[i][j][0] = ft_atoi(&line[k]);
			if (sudoku[i][j][0] < 0 || sudoku[i][j][0] > n)
				return (ft_free_and_return(line));
			while (ft_isspace(line[k]))
				k++;
			while (!(ft_isspace(line[k])) && line[k] != '\0')
				k++;
			j++;
		}
		if (j != n || line[k] != '\0')
			return (ft_free_and_return(line));
		free(line);
		i++;
		if (get_next_line(fd, &line) != 1)
			break;
	}
	if (i != n || get_next_line(fd, &line) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			ft_read_input(int fd, int ****sudoku)
{
	char	*line;
	int		n;

	line = NULL;
	if (get_next_line(fd, &line) != 1)
		return (EXIT_FAILURE);
	n = ft_get_dimension(line);
	if (n < 4 || ft_sqrt(n) == 0)
		return (ft_free_and_return(line));
	*sudoku = ft_initialize_grid(n);
	if (!*sudoku)
		return (ft_free_and_return(line));
	if (ft_read_to_grid(fd, n, *sudoku, line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (n);
}

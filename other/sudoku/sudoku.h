/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:44:29 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/28 09:40:09 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# define EXIT_FAILURE 1

int		ft_read_input(int fd, int ****sudoku);
void	ft_update_sudoku(int ***sudoku, int n, int all);
int		ft_is_valid(int ***sudoku, int n);
int		ft_solve_sudoku(int ***sudoku, int **solution, int n);
void	ft_print_sudoku(int ***sudoku, int n);
void	ft_print_solution(int **solution, int n);

#endif

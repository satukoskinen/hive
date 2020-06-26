/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 15:54:14 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/25 20:47:43 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lst.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *p;

	p = *alst;
	new->next = p;
	*alst = new;
}

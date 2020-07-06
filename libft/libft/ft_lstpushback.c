/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:31:05 by skoskine          #+#    #+#             */
/*   Updated: 2020/07/05 11:36:57 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstpushback(t_list *alst, t_list *new)
{
	t_list *p;

	p = alst;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

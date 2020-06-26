/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:08:01 by skoskine          #+#    #+#             */
/*   Updated: 2020/06/25 20:48:37 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lst.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	new = f(lst);
	if (new == NULL)
		return (NULL);
	if (lst->next != NULL)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}

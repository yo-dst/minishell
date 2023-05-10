/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_dpt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:54:57 by jbettini          #+#    #+#             */
/*   Updated: 2022/04/03 13:10:13 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_dpt(t_list *lst)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!tab)
		return (NULL);
	while (lst)
	{
		tab[i++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}

t_list	*ft_dpt_to_lst(char **tab)
{
	int		i;
	t_list	*lst;

	i = -1;
	lst = NULL;
	while (tab[++i])
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(tab[i])));
	return (lst);
}

t_list	*ft_dpt_to_lst_nl(char **tab)
{
	int		i;
	t_list	*lst;

	i = -1;
	lst = NULL;
	while (tab[++i])
		ft_lstadd_back(&lst, ft_lstnew(ft_strjoin(tab[i], "\n")));
	return (lst);
}

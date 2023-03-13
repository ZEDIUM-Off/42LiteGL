/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:18:04 by  mchenava         #+#    #+#             */
/*   Updated: 2023/01/16 10:30:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_tab(void *tab, int len)
{
	int	i;

	i = 0;
	while (i < len || ((char **)tab)[i])
	{
		free(((char **)tab)[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

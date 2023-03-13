/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:46:19 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 14:46:37 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
		return (ft_memalloc(size));
	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	new = ft_memalloc(size);
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}

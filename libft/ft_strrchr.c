/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:25:36 by mchenava          #+#    #+#             */
/*   Updated: 2022/11/16 11:09:43 by  mchenava        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strrchr(const char *s, int c)
// {
// 	char	*last;

// 	last = NULL;
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			last = (char *)s;
// 		s++;
// 	}
// 	if (last)
// 		return (last);
// 	if (c == '\0' || c < 0 || c > 255)
// 		return ((char *)s);
// 	return (NULL);
// }

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i > 0 && s[i] != (char)c)
		i--;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

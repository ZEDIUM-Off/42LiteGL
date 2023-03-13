/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:23:08 by mchenava          #+#    #+#             */
/*   Updated: 2022/11/17 08:43:54 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_str_cut(char **dest, char const *src, char sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (src[i] && ft_count_words(src, sep) - k > 0)
	{
		while (src[i] && src[i] == sep)
			i++;
		j = i;
		while (src[j] && src[j] != sep)
			j++;
		dest[k] = (char *)malloc(sizeof(char) * (j - i + 1));
		if (!dest[k])
			return (ft_free_tab(dest, k));
		j = 0;
		while (src[i] && src[i] != sep)
			dest[k][j++] = src[i++];
		dest[k++][j] = '\0';
	}
	dest[k] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_str_cut(tab, s, c));
}

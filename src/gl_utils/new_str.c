/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:59:43 by  mchenava         #+#    #+#             */
/*   Updated: 2023/03/13 21:25:05 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lite_gl.h>

char	*new_str(char *str)
{
	char	*new;
	int		len;

	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(new, str, len);
	return (new);
}

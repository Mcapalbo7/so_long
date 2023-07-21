/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:11:15 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/10 17:04:57 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1copy;
	size_t	i;
	size_t	c;
	size_t	a;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	c = 0;
	while (s1[c] && ft_strchr(set, s1[c]) != '\0')
		c++;
	a = ft_strlen((char *) s1);
	while (a > c && ft_strchr(set, s1[a - 1]) != '\0')
		a--;
	s1copy = (char *) malloc(sizeof(*s1) * (a - c + 1));
	if (!s1copy)
		return (NULL);
	i = 0;
	while (c < a)
	{
		s1copy[i++] = s1[c++];
	}
	s1copy[i] = 0;
	return ((char *)s1copy);
}

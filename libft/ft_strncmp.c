/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:01:57 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/07 21:03:16 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	a;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) str1;
	ptr2 = (unsigned char *) str2;
	a = 0;
	while ((ptr1[a] != '\0' || ptr2[a] != '\0') && a < n)
	{
		if (ptr1[a] > ptr2[a])
		{
			return (1);
		}
		else if (ptr1[a] < ptr2[a])
		{
			return (-1);
		}
		a++;
	}
	return (0);
}

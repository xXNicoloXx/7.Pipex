/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:09:07 by ngriveau          #+#    #+#             */
/*   Updated: 2023/02/13 19:27:23 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *src, char *cmp, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = 0;
	str = (char *) src;
	while (src[i] != '\0' || i == 0)
	{
		k = i;
		while (src[k] == cmp[j] && cmp[j] != '\0')
		{
			k++;
			j++;
		}
		if (k > n)
			return (0);
		if (cmp[j] == '\0')
			return (&str[i]);
		i++;
		j = 0;
	}
	return (0);
}

// int main(void)
// {
// 	 int i = 0;
//     while (i < 20)
//     {
//     char *srcstr = "Bonjour les amis comment ca va ?";
//     char *cmpstr = "s";
//     printf("%s\n", strnstr(srcstr, cmpstr, i));
//     printf("%s\n\n\n", ft_strnstr(srcstr, cmpstr, i));
//     i++;
//     }
// }
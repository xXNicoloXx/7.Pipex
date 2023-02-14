/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:32:29 by ngriveau          #+#    #+#             */
/*   Updated: 2023/02/13 19:27:25 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int lettre)
{
	int				i;
	unsigned char	ch;	

	i = ft_strlen(str);
	ch = (char) lettre;
	if (str == NULL)
		return (NULL);
	while (i >= 0)
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

//  int main (void)
//  {
//      char *texte = "bonjour";
//     int lettre = 's';
// 	char * empty = (char*)calloc(1, 1);
//     printf("1:|%s|\n", strrchr(texte, lettre));
//     printf("2:|%s|", ft_strrchr(texte, lettre));    
//  }
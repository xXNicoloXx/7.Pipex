/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:40:05 by ngriveau          #+#    #+#             */
/*   Updated: 2023/02/13 19:27:40 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_begin(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	int		in_set;

	in_set = 0;
	i = 0;
	j = 0;
	while (s1[i])
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i++;
	}
	return ((char *) s1 + i);
}

static char	*find_end(char *s1, char *set, char *begin)
{
	size_t	i;
	size_t	j;
	int		in_set;

	in_set = 0;
	i = ft_strlen(s1) - 1;
	j = 0;
	while (s1 + i >= begin)
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i--;
	}
	if (s1 + i < begin)
		return ((char *) begin);
	return ((char *) s1 + i);
}

static char	*fill_str(char *begin, char *end)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (end - begin + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (begin + i <= end)
	{
		new[i] = begin[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*begin;
	char	*end;
	char	*new;

	begin = find_begin(s1, set);
	end = find_end(s1, set, s1);
	if (!s1[0] || end < begin)
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
	}
	else
		new = fill_str(begin, end);
	if (!new)
		return (NULL);
	return (new);
}

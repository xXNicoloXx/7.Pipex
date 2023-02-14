/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:26:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/15 12:04:58 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int c, int fd)
{
	c = c + 48;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < -2147483647)
	{
		write(fd, "-", 1);
		write(fd, "2147483648", 10);
		return ;
	}	
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}	
	if (nb < 10)
		ft_putnbr(nb, fd);
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

// int main()
// {
//     int fd = open("test.txt", O_WRONLY);
// 	ft_putnbr_fd(10, fd);
// }

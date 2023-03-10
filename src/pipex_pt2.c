/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:57:46 by ngriveau          #+#    #+#             */
/*   Updated: 2023/03/09 16:52:50 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_int(t_pip *s, int ac, char **av, char **ev)
{
	s->i = -1;
	s->ac = ac;
	s->av = av;
	s->env = ev;
	s->error = 0;
	s->path = NULL;
	if (ac != 5)
		return (write(1, "\e[31;1mError Arguments\n\e[0m", 28), -1);
	while (s->env[++s->i])
	{
		if (ft_strncmp(s->env[s->i], "PATH", 4) == 0)
			s->path = ft_split(&s->env[s->i][5], ':');
	}
	s->fdin = open(av[1], O_RDONLY);
	s->fdout = -1;
	if (s->fdin == -1)
		perror(av[1]);
	pipe(s->fdpip1);
	return (0);
}

int	ft_1st_cmd(t_pip *s)
{
	int	i;

	i = -1;
	s->id1 = fork();
	if (s->id1 == 0 && s->fdin != -1)
	{
		dup2(s->fdin, 0);
		dup2(s->fdpip1[1], 1);
		ft_close_fd(s, s->fdpip1);
		if (ft_exe_cmd(s, 2) == -1)
			exit(1);
	}
	if (s->id1 == 0)
	{
		while (s->path[++i])
			free(s->path[i]);
		free(s->path);
		ft_close_fd(s, s->fdpip1);
		exit(1);
	}
	return (0);
}

int	ft_2nd_cmd(t_pip *s)
{
	int	i;

	i = -1;
	s->id2 = fork();
	if (s->id2 == 0 && s->fdout != -1)
	{
		dup2(s->fdpip1[0], 0);
		dup2(s->fdout, 1);
		ft_close_fd(s, s->fdpip1);
		if (ft_exe_cmd(s, 3) == -1)
			exit(1);
	}
	if (s->id2 == 0)
	{
		while (s->path[++i])
			free(s->path[i]);
		free(s->path);
		ft_close_fd(s, s->fdpip1);
		exit(1);
	}
	return (0);
}

void	ft_free(t_pip *s)
{
	int	i;

	i = -1;
	while (s->path[++i])
		free(s->path[i]);
	free(s->path);
}

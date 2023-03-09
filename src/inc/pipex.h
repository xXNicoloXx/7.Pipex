/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:37:23 by ngriveau          #+#    #+#             */
/*   Updated: 2023/03/09 16:54:26 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "../../libft/libft.h"
# include <sys/wait.h>

typedef struct s_pip
{
	int		i;
	int		ac;
	char	**av;
	char	**env;
	char	**path;

	int		error;

	int		fdin;
	int		fdout;
	int		fdpip1[2];
	int		id1;
	int		id2;

}				t_pip;

int		ft_2nd_cmd(t_pip *s);
int		ft_1st_cmd(t_pip *s);
int		ft_error_int(t_pip *s, int ac, char **av, char **ev);
void	ft_free(t_pip *s);

void	ft_close_fd(t_pip *s, int *fdpip1);
int		ft_av_is_cmd(t_pip *s, int nbcmd);
int		ft_exe_cmd_pt2(t_pip *s, char **cmd);
int		ft_exe_cmd(t_pip *s, int nbcmd);
int		main(int ac, char **av, char **envp);

#endif

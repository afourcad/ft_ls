/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:11:04 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/06 18:42:23 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_options(char *str, char *prog, int *options)
{
	int	i;

	i = 1;
	OPT_OK = 1;
	while (str[i])
	{
		if (str[i] == 'l')
			OPT_L = 1;
		else if (str[i] == 'R')
			OPT_MR = 1;
		else if (str[i] == 'a')
			OPT_A = 1;
		else if (str[i] == 'r')
			OPT_R = 1;
		else if (str[i] == 't')
			OPT_T = 1;
		else
		{
			printf("%s: illegal option -- %c\nusage: %s [-Ralrt] [file ...]\n"
					, prog, str[i], prog);
			//fonction free
			exit(1);
		}
		++i;
	}
}

t_path	*ft_rec_arguments(int ac, char **av, int i)
{
	DIR	*dir;
	t_path	*path;

	if ((path = malloc(sizeof(*path))) == NULL)
		return (NULL);
	if (i >= ac)
		return (NULL);
	if ((dir = opendir(av[i])) == NULL)
	{
		ft_printf("%s: %s: No such file or directory\n", av[0], av[i]);
		free(path);
		return (ft_rec_arguments(ac, av, ++i));
	}
	else 
	{
		path->path = ft_strdup(av[i]);
		path->next = ft_rec_arguments(ac, av, ++i);
	}
	closedir(dir);
	return (path);
}

t_path	*ft_get_arguments(int ac, char **av, int *options)
{
	int		i;
	DIR		*dir;
	t_path	*path;

	i = 1;
	if ((path = malloc(sizeof(*path))) == NULL)
		return (NULL);
	if (ac  && ac < 2)
	{
		path->path = ft_strdup(".");
		path->next = NULL;
	}
	else
	{
		while (av[i][0] == '-')
		{
			ft_get_options(av[i], av[0], options);
			++i;
		}
		if (i < ac)
			path = ft_rec_arguments(ac, av, i);
	}
	return (path);
}

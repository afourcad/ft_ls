/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:03:27 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/03 17:03:24 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include "ft_printf.h"
#include "libft.h"

int	main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*dp;
	struct stat		info;
	struct passwd	*pass_n;
	struct group	*pass_g;
	char			*path;
	char			*a_path;

	path = ac < 2 ? ".": av[1];
	dir = opendir(path);
	if (dir == NULL)
		return (0);
	while ((dp = readdir(dir)) != NULL)
	{
		/*if (dp->d_name[0] == '.')
		{
			stat(dp->d_name, &info);
			ft_printf("Total: %d\n", info.st_blksize);
		}
		if (dp->d_name[0] != '.')
		{*/
			a_path = ft_strjoin(path, "/");
			a_path = ft_strjoin(a_path, dp->d_name);
			stat(a_path, &info);
			pass_n = getpwuid(info.st_uid);
			pass_g = getgrgid(info.st_gid);
			ft_printf("Nom: %s\n", dp->d_name);
			ft_printf("Type: %hhu\n", dp->d_type);
			ft_printf("Modes: %lo\n", info.st_mode);
			ft_printf("Nombre de liens: %d\n", info.st_nlink);
			ft_printf("Proprietaite: %s\n", pass_n->pw_name);
			ft_printf("Groupe: %s\n", pass_g->gr_name);
			ft_printf("Taille: %lld octets\n", info.st_size);
			ft_printf("Date de derniere modification: %s\n", ctime(&info.st_mtimespec.tv_sec));
	//	}
	}
	closedir(dir);
	return (0);
}

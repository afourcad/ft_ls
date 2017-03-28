/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:03:27 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/28 20:25:17 by afourcad         ###   ########.fr       */
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

int	main()
{
	DIR				*dir;
	struct dirent	*dp;
	struct stat		info;
	struct passwd	*pass_n;
	struct group	*pass_g;

	dir = opendir(".");
	if (dir == NULL)
		return (0);
	while ((dp = readdir(dir)) != NULL)
	{
		stat(dp->d_name, &info);
		pass_n = getpwuid(info.st_uid);
		pass_g = getgrgid(info.st_gid);
		printf("Nom: %s\n", dp->d_name);
		printf("Type: %hhu\n", dp->d_type);
		printf("Modes: %hu\n", info.st_mode);
		printf("Nombre de liens: %d\n", info.st_nlink);
		printf("Proprietaite: %s\n", pass_n->pw_name);
		printf("Groupe: %s\n", pass_g->gr_name);
		printf("Taille: %lld octets\n", info.st_size);
		printf("Date de derniere modification: %s\n", ctime(&info.st_mtimespec.tv_sec));
	}
	closedir(dir);
	return (0);
}

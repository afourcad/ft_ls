/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:13:57 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/06 18:57:59 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include "ft_printf.h"
# include "libft.h"

# define TRUE 1
# define FALSE 0

# define NBR_OPT 5
# define OPT_OK options[0]
# define OPT_L options[1]
# define OPT_MR options[2]
# define OPT_A options[3]
# define OPT_R options[4]
# define OPT_T options[5]

typedef struct	 dirent	t_dirent;

typedef struct	s_info
{
	char			*name;
	char			*full_name;
	unsigned char	type;
	struct	stat	stat;
	struct	passwd	user;
	struct	group	group;
	struct	s_info	*next;
}				t_info;

typedef struct	s_path
{
	char			*path;
	t_info			*begin;
	struct	s_path	*next;
}				t_path;

t_path	*ft_get_arguments(int ac, char **av, int *options);
void	ft_ls(t_path *path, int *options);
void	ft_get_ls(t_path *path, int *options);

#endif

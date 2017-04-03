/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:13:57 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/03 20:30:32 by afourcad         ###   ########.fr       */
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

# define OPT_L options[0]
# define OPT_MR options[1]
# define OPT_A options[2]
# define OPT_R options[3]
# define OPT_T options[4]

typedef struct	s_path
{
	char			*path;
	struct	s_path	*next;
}				t_path;

t_path	*ft_get_arguments(int ac, char **av, int *options);
void	ft_ls(t_path *path, int *options);

#endif

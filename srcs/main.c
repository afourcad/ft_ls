/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:07:37 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/06 18:58:19 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_path	*path;
	int		options[NBR_OPT];

	ft_bzero(options, NBR_OPT);
	path = ft_get_arguments(ac, av, options);
	ft_get_ls(path, options);
	ft_ls(path, options);
	return (0);
}

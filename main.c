/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:26:54 by skythoma          #+#    #+#             */
/*   Updated: 2019/05/21 18:27:28 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "error", 1);
		return (0);
	}
	if (!parse(argv[1]))
		write(1, "error\n", 6);
	return (0);
}
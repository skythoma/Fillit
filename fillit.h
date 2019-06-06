/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:30:41 by skythoma          #+#    #+#             */
/*   Updated: 2019/06/05 13:32:57 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "getnextline/get_next_line.h"

typedef	struct	s_array
{
	//used to assign each piece a letter
	char	letter;
	char	*whole_array;
	int		tetra;
	int		x[4];
	int		y[4];
} 				t_array;
/*
t_array *sp;

sp->letter = "five hunnid gwap gng";

sp = malloc(sizeof(t_array));
*/
char		findmap(char *files);
/*int			fillmap(char *coordinates);
*/
int			validate_tetri(int files);
int			read_files(const char *files);
int			parse(char *files);
t_array		get_coordinates(int tetra);
int			touches(char *line, int a, int b);
void		makemap(int map);

#endif

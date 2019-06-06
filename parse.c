/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skythoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 08:47:45 by skythoma          #+#    #+#             */
/*   Updated: 2019/06/05 13:32:45 by skythoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//How do we access the tets stored in the strucct and place them on the map
/*int		fillmap(char *coordinates)
{

}*/

/*
void	makemap(int map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < map)
	{
		while (y < map)
		{
			ft_putchar('.');
			y++;
		}
	y = 0;
	x++;
	}
}

//Make a map by reading through the entire file and then dividing by 21 to
//get the exact number of tets given
char	findmap(char *files)
{
	char buff[BUFF_SIZE + 1];
	int	numoftets;
	int i;
	int x;
	int y;
	char	map[256];
	int count;
	int bytes;
	int fd;

	bytes = 0;
	i = 1;
	x = 0;
	y = 0;
	count = 0;
	while (bytes == read(fd, buff, BUFF_SIZE) > 0)
	{
		numoftets = (bytes + 1) / 21;
		printf("%d\n", numoftets);
	}
	while (numoftets[count])
	{
		numoftets = (numoftets * 4);
		if (i * i >= numoftets)
			return (i);
		else
			i++;
		count++;
	}
	return (0);
}

tetrimino	get_coordinates(int tetraa)
{
	tetrimino tetra1;
	int count;
	int a;
	int b;
	int n;

	n = 0;
	a = 0;
	b = 0;
	count = 0;

	n = n + 1;
	tetra1.tetra = n;
	while (count != 21)
	{
		while (tetraa[a][b] != '\n')
		{
			if (tetraa[a][b] == '#')
			{
				tetra1.x = a;
				tetra1.y = b;
			}
			b++;
			count++;
		}
		b = 0;
		a++;
		count++;
	}
	if (tetra1.tetra == 1)
	{
		(tetra1.letter = 'A');
	}
	else
	{
		(tetra1.letter = 'A' + 1);
	}
	return (tetra1);
}

int	touches(char *line, int a, int b)
{
	int touch;

	touch = 0;
	if (line[a][b] == '#')

			while (line[a][b] != '\0')
			{
				touch = 0;
				if (b < 3)
				{
					if (line[a][b + 1] == '#')
						touch += 1;
				}
				if (b > 0)
				{
					if (line[a][b - 1] == '#')
						touch += 1;
				}
				if (a > 0)
				{
					if (line[a - 1][b] == '#')
						touch += 1;
				}
				if (a < 3)
				{
					if (line[a + 1][b] == '#')
						touch += 1;
				}
				return (touch);
			}
}
*/
//need to check amount of empty spaces, amount of hashes, amount of newlines between each tetromino and in each tetromino
int	validate_tetri(int files, t_array *sp)
{
	int		count;
	int		touch;
	int		x;
	int		y;
	char	**line;
	char	*buf;

	count = 0;
	x = 0;
	y = 0;
	line = NULL;
	touch = 0;
	sp = NULL;

	buf = (char *)malloc(sizeof(char) + 1);
	sp->whole_array = (char *)malloc(sizeof(char) + 1);
	while ((x = read(files, buf, 21)))
	{
		printf("%d\n", x);
		printf("%s\n", buf);
	}

	/*
	while (*line)
	{
		if (line[x][y] == ' ')
			return (-1);
		if (line[x][y] != '.' || line[x][y] != '#')
		   return (-1);
		if (line[x][y] == '#')
		{
			touch += touches(*line, x, y);
		}
		y++;
		if (y == 4)
			y = 0;
			x++;
		if (x == 4)
		{
			break ;
		}
		line++;
	}
	*/
	if (!(touch == 6 || touch == 8))
			return (-1);
	return (1);
}

int	read_files(const char *files, t_array *sp)
{
	int	file_descriptor;

	file_descriptor = open(files, O_RDONLY);
	if (file_descriptor == -1)
		return (-1);
	if (file_descriptor == 0)
		return (-1);
	if (!(validate_tetri(file_descriptor, sp)))
		return (-1);
	return (1);
}

int parse(char *files)
{
	int	 tetris;
	t_array		*sp;
//	char *savedtets;
//	int map;

	sp = (t_array *)malloc(sizeof(t_array));
	if ((tetris = read_files(files, sp)) == 1)
	{
	   printf("here");	
		/*if(!(savedtets = get_coordinates(files)))
			return (0);
		*/
	}
	else
	{
		return (0);
	}
	/*
	map = findmap(files);
	if (!(makemap(map)))
		return (-1);
	if (!(fillmap(savedtets, map)))
		return (-1);
*/
	return (0);
}

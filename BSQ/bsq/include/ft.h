/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:01:21 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/15 20:21:16 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	fill;
	char	**map;
	int		**dp;
}			t_map;

int				init(int file_desc);
int				init2(t_map *table);
int				init3(t_map *table);
void			ft_stdin(void);
int				iter_paths(char **paths, int size);
void			solve(t_map *table);
void			display(t_map *table, int maxi, int maxj, int i);
unsigned int	ft_atoi(char *str);
void			error(void);
unsigned int	get_length(int file_desc);
char			*get_line(int length, int file_desc);
char			*ft_strncpy(char *src, unsigned int n);
char			**ft_split(char *str, int len, char set);
int				ft_strlen(char *str);
void			free_func(t_map *table);
int				ft_min(int i1, int i2);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:39:15 by seryilma          #+#    #+#             */
/*   Updated: 2021/12/05 23:15:56 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNCS_H
# define FT_FUNCS_H

void	ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(char *str);
int		check_case(int position);
int		is_double_row(int position, int tower_height);
int		is_double_column(int position, int tower_height);
#endif

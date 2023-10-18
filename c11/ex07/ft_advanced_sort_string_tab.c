/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:19:12 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/08 22:22:36 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		f;
	char	*tmp;

	if (*tab == 0)
		return ;
	while (1)
	{
		f = 1;
		i = 1;
		while (tab[i] != 0)
		{
			if (cmp(tab[i - 1], tab[i]) > 0)
			{
				tmp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = tmp;
				f = 0;
			}
			i++;
		}
		if (f)
			return ;
	}
}

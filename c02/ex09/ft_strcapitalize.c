/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 05:29:19 by esoylu            #+#    #+#             */
/*   Updated: 2021/11/29 04:44:06 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
int	is_alph(char c)
{
	if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}

int	is_upper(char c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	return (0);
}

int	is_letter(char c)
{
	if ((c <= 'z' && c >= 'a') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	f;
	int	i;

	i = 0;
	f = 1;
	while (str[i] != '\0')
	{
		if (is_upper(str[i]))
			str[i] += 'a' - 'A';
		if (f && str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A' - 'a';
		f = 0;
		if (!is_alph(str[i]))
			f = 1;
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stremplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 20:46:04 by acalleja          #+#    #+#             */
/*   Updated: 2017/12/17 22:23:40 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stremplace(char *str, char a)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = '\0';
		i++;
	}
	return (str);
}

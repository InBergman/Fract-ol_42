/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:33:52 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:33:55 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

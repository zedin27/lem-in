/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:16:09 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/14 13:43:55 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*tmp;
	char	*dup;

	tmp = s1;
	if (!(dup = ft_strcdup(s2, '\n')))
		return (NULL);
	s1 = ft_strjoin(tmp, dup);
	return (s1);
}

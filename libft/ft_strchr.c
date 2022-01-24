/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:47:36 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/20 12:25:38 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (char) c)
		{
			return ((char *)s);
		}
		++s;
	}
	if ((char) c == 0)
		return ((char *)s);
	return (0);
}

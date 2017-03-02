/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:53:07 by kboucaud          #+#    #+#             */
/*   Updated: 2016/11/29 14:53:09 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	if (nb <= 2147483647 || nb >= 0)
	{
		while (i * i != nb && i < 161464936 && i * i < nb)
			i++;
		if (i * i == nb)
			return (i);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 00:17:23 by twalton           #+#    #+#             */
/*   Updated: 2017/06/10 00:17:25 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort(int *arr, int size)
{
	int i;
	int placehold;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			placehold = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = placehold;
			i = -1;
		}
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:42:05 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/05 19:05:50 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int convertbinary(char *id, char c)
{
	int pid;
	int i;

	i = 0;
	pid = ft_atoi(id);
	if (pid == -1)
		return 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(100);
	}
	return 0;
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 3)
		while (argv[2][i])
		{
			convertbinary(argv[1], argv[2][i++]);
		}
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:15:24 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/05 19:55:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void handler(int sig, siginfo_t *info, void *vp)
{
	int i;
	int *signumber;

	i = 0;
	signumber = malloc(sizeof(int) * 9);
	while(i < 8)
		signumber[i++] = sig;
	signumber[i] = 0;
	i = 0;
	while(signumber[i])
		{printf("%d",signumber[i]);
		}
}

int main()
{
	struct sigaction sa;

	sa.sa_sigaction = handler;
	sa.sa_mask = 0;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("PID: %d\n",getpid());
	while(1)
		{
			pause();
		}
}
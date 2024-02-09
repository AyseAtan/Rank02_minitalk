/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:07:06 by aatan             #+#    #+#             */
/*   Updated: 2024/02/06 12:16:15 by aatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	bitcount;
	static char	c;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
	{
		c = (c << 1) | 1;
		bitcount++;
	}
	else if (signal == SIGUSR2)
	{
		c = (c << 1) | 0;
		bitcount++;
	}
	if (bitcount == 8)
	{
		write(1, &c, 1);
		bitcount = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Failed to change SIGUSR2's behavior");
	while (1)
	{
		pause();
	}
	return (0);
}

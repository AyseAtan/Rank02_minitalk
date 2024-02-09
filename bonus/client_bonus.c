/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:25:20 by aatan             #+#    #+#             */
/*   Updated: 2024/02/06 13:04:37 by aatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	end(int signal)
{
	(void)signal;
	ft_printf("Message correctly received!\n");
	exit(EXIT_SUCCESS);
}

void	chartobit(int pid, char c)
{
	static int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(400);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		signal(SIGUSR1, end);
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			chartobit(pid, argv[2][i]);
			i++;
		}
		chartobit(pid, '\0');
	}
	else
	{
		ft_printf("Usage: %s <receiver_pid> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:27:44 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 18:30:45 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minitalk.h"

static void	send_endsig(int pid)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		kill(pid, SIGUSR2);
		index++;
		usleep(500);
	}
}

static int	send_to_server(char *argv, int pid)
{
	int	index;
	int	index_j;

	index = 0;
	while (argv[index])
	{
		index_j = 7;
		while (index_j >= 0)
		{
			if ((argv[index] >> index_j & 1) == 1)
			{
				if (kill(pid, SIGUSR1))
					return (0);
			}
			else if ((argv[index] >> index_j & 1) == 0)
			{
				if (kill(pid, SIGUSR2))
					return (0);
			}
			index_j--;
			usleep(500);
		}
		index++;
	}
	return (send_endsig(pid), 1);
}

static int	check_pid(char *argv, int *pid)
{
	int	index;

	index = 0;
	while (argv[index])
	{
		if (!ft_isdigit(argv[index++]))
			return (0);
	}
	*pid = ft_atoi(argv);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		if (!check_pid(argv[1], &pid))
			return (ft_putendl_fd("Wrong PID format.", 1), 2);
		if (!send_to_server(argv[2], pid))
			return (ft_putendl_fd("Failure in attempting to send signals.", 1),
				3);
	}
	else
		return (ft_putendl_fd("USAGE: ./client 'pid' 'message'", 1), 1);
	return (EXIT_SUCCESS);
}

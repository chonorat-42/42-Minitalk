/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:26:56 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/25 13:21:11 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minitalk.h"

char *g_str;

static void	get_str(char *c, int *bits, int *end)
{
	char	*temp;

	temp = NULL;
	if (*end == 8)
	{
		ft_putstr_fd(g_str, 1);
		free(g_str);
		g_str = NULL;
	}
	else
	{
		temp = g_str;
		g_str = ft_strjoin(temp, c);
		free(temp);
	}
	*end = 0;
	*bits = 0;
	*c = '\0';
}

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = '\0';
	static int	bits = 0;
	static int	end = 0;

	(void)info;
	(void)context;
	if (!g_str)
		g_str = ft_strdup("");
	if (signum == SIGUSR1)
	{
		c = (c << 1) | 1;
		end = 0;
	}
	else if (signum == SIGUSR2)
	{
		c = c << 1;
		end++;
	}
	bits++;
	if (bits == 8)
		get_str(&c, &bits, &end);
}

int	main(void)
{
	struct sigaction	server;

	sigemptyset(&server.sa_mask);
	ft_printf("PID: %d\n", getpid());
	server.sa_sigaction = sig_handler;
	server.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &server, NULL) == -1)
		return (ft_putendl_fd("Error", 1), 1);
	if (sigaction(SIGUSR2, &server, NULL) == -1)
		return (ft_putendl_fd("Error", 1), 2);
	while (1)
		sleep(1);
	return (0);
}

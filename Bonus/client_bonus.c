

#include "minitalk.h"

void	convert_char_to_bits(char c, pid_t pid)
{
	int i;

	i = 7;
	while(i >= 0)
	{
		if (c & (1 << i))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		i--;
		usleep(TIME);
	}
}

int		main(int argc, char **argv)
{
	int i;
	pid_t pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while(argv[2][i] != '\0')
		{
			convert_char_to_bits(argv[2][i], pid);
			i++;
		}
	}
	else
		write(2, "usage: ./client <pid> <string_to_send>\n", 38);
	return (0);
}

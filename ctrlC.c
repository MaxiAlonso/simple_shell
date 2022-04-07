#include "main.h"

void ctrlC(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDIN_FILENO, "\n$ ", 3);
}

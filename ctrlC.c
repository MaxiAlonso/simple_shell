#include "main.h"

/**
 * ctrlC - function to catch the ctrl + c signal
 * @sig_num: the signal sent when we press Ctrl+C
 **/

void ctrlC(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDIN_FILENO, "\n$ ", 3);
}

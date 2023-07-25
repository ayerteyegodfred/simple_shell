#include "header.h"

/**
 * main - Program Entry
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Returns condi
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd, **com;
	int count = 0, i, condi = 1, stat = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handle);

	while (condi)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getln();
		if (input[0] == '\0')
			continue;
		history(input);
		com = separator(input);
		for (i = 0; com[i] != NULL; i++)
		{
			cmd = parse_cmd(com[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(com);
				exit_bul(cmd, input, argv, count, stat);
			}
			else if (check_builtin(cmd) == 0)
			{
				stat = handle_builtin(cmd, stat);
				free(cmd);
				continue;
			}
			else
			{
				stat = check_cmd(cmd, input, count, argv);
			}
			
			free(cmd);
		}
		free(input);
		free(com);
		wait(&stat);
	}
	return (stat);
}

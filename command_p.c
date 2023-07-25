#include "header.h"

/**
 * parse_cmd - Passes function
 * @input: String from stdin
 * Return: Parsed strings
 */

char **parse_cmd(char *input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argument = _strk(input, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = _strk(NULL, "\n\t\r\a ");
	}
	arguments[i] = NULL;
	return (arguments);
}

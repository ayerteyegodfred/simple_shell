#include "header.h"

/**
 * separator - Separates condi ansstdin
 * @input: String from stdin
 * Return: Parsed strings
 */

char **separator(char *input)
{
	char **condis;
	char *condi;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	condis = malloc(sizeof(char *) * buffsize);
	if (!condis)
	{
		free(condis);
		perror("hsh");
		return (NULL);
	}
	condi = _strk(input, ";&");
	for (i = 0; condi; i++)
	{
		condis[i] = condi;
		condi = _strk(NULL, ";&");
	}
	condis[i] = NULL;

	return (condis);
}

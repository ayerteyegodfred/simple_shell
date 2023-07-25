#include "header.h"

/**
* _getln - read input
* Return: the input on a buff
*/
char *_getln()
{
	int i, rd, buffs = BUFSIZE;
	char c = 0, *buff, *buf;

	buff = malloc(buffs);
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
			return (enter(buff));
		if (i >= buffs)
		{
			buff = realloc(buff, (buffs + 2));
			if (buff == NULL)
			{
				free(buff);
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	buf = space(buff);
	free(buff);
	hashtag_handler(buf);
	return (buf);
}
/**
 * enter - Handles newline character input
 * @string: String to be handled
 * Return: Empty string
 */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * space - Modifies the input string to remove preceeding whitespaces
 * @str: Input to be modifies
 * Return: Returns the modified string
 */
char *space(char *str)
{
	int i, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; str[i] == ' '; i++)
		;
	for (; str[i + 1] != '\0'; i++)
	{
		buff[j] = str[i];
		j++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}
/**
 * hashtag_handler - Removes everything after Start logo'#'
 * @buff: input buff
 * Return: nothing
 */
void hashtag_handler(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ' && buff[i + 1] == ' ')
		{
			buff[i] = '\0';
		}
	}
}

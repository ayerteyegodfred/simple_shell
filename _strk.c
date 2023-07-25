#include "header.h"
/**
 * check_delim - Checks if a character matchs any character
 * @c: Check char
 * @str: string delimiters
 * Return: 1 success, 0 failure
 */
unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}
/**
 * _strk - Extracts tok
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next token
 */
char *_strk(char *str, const char *delim)
{
	static char *tok;
	static char *tokN;
	unsigned int i;

	if (str != NULL)
		tokN = str;
	tok = tokN;
	if (tok == NULL)
		return (NULL);
	for (i = 0; tok[i] != '\0'; i++)
	{
		if (check_delim(tok[i], delim) == 0)
			break;
	}
	if (tokN[i] == '\0' || tokN[i] == '#')
	{
		tokN = NULL;
		return (NULL);
	}
	tok = tokN + i;
	tokN = tok;
	for (i = 0; tokN[i] != '\0'; i++)
	{
		if (check_delim(tokN[i], delim) == 1)
			break;
	}
	if (tokN[i] == '\0')
		tokN = NULL;
	else
	{
		tokN[i] = '\0';
		tokN = tokN + i + 1;
		if (*tokN == '\0')
			tokN = NULL;
	}
	return (tok);
}

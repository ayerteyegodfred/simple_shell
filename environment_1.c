#include "header.h"

/**
 * create_envi - Creates  Enviroment array Variables
 * @envi: Array to store Enviroment Variables
 */

void create_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}

/**
 * free_env - Frees the memory 
 * @env:  Array of Environment
 */

void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}

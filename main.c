#include "get_next_line.h"
#include "stdio.h"
#include "unistd.h"

int main ()
{
	char *line;

	line = NULL;
	while (get_next_line(-42, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}

# GET NEXT LINE

This is a function to read lines from a file descriptor(s).

## DEPENDENCIES

- C compiler.

## USE

This is a little example of its use.
main.c
```
#include "get_next_line.h"

int	main()
{
	char	*line;

	while(get_next_line(0, &line))
	{
		printf("%s\n", line);
		free(line);
	}	
	printf("%s", line);
	free(line);
	return (0);
}
```

You may compile this with `gcc main.c get_next_line.c get_next_line_utils.c -o gnl`, and run `./gnl`.

*If you want to use multiples fd compile with bonus files*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

int main(void)
{
	int			i;
	char		*msg;
	char		*saved_msg;

	i = 1;
	while (i < 200)
	{
		printf("i = %d\n", i);

		msg = malloc(15);
		if (!msg)
			return 1;
		saved_msg = msg;

	    strcpy(msg, "Short message.");
		printf("%s\n", (char *)saved_msg);

		msg = realloc(msg, 17 * i * i);
		if (!msg)
			return 1;
		
		strcpy(msg, "A longer message.");
		printf("%s\n", (char *)saved_msg);

		usleep(25000);

		free(msg);
		msg = NULL;
		i++;
	}
	return 0;
}
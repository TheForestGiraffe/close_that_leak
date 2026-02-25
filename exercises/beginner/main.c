#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int trim(char *s)
{
    while (*s == ' ')
        s++;
    return 0;
}

static char *grow_and_append(char *s, int i)
{
    size_t need = strlen(s) + 32;
    char *new_s = realloc(s, need);
    if (!new_s)
        return NULL;

    strcat(new_s, " + ");
    char tmp[16];
    snprintf(tmp, sizeof(tmp), "%d", i);
    strcat(new_s, tmp);
    return new_s;
}

int main(void)
{
    int   i = 1;
    char *msg = strdup("   start");
    if (!msg) return 1;

    while (i < 5)
    {
        printf("i=%d\n", i);

        if (trim(msg) != 0)
            break;

        msg = grow_and_append(msg, i);
        if (!msg) return 1;
 
        printf("%s\n", msg);
        usleep(20000);
        i++;
    }

    free(msg);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *append_number(char *s, int n)
{
    /* allocate a NEW string */
    size_t need = strlen(s) + 2;          // 1 digit + '\0'
    char *out = malloc(need);
    if (!out)
    {
        free(s);                          // <-- hidden ownership on failure
        return NULL;
    }

    strcpy(out, s);
    out[strlen(out)] = (char)('0' + n);
    out[strlen(s) + 1] = '\0';

    free(s);                              // <-- hidden ownership on success too
    return out;
}

int main(void)
{
    char *msg = strdup("A");
    if (!msg)
        return 1;

    msg = append_number(msg, 1);
    if (!msg)
        return 1;

    printf("%s\n", msg);

    free(msg);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct s_app {
    char *buffer;     // owned by app
} t_app;

static void destroy_app(t_app *app, int code)
{
    free(app->buffer);
    exit(code);
}

static char *read_line(void)
{
    // imagine this returns a heap string or NULL on failure
    return NULL;
}

/* PROBLEM: helper does cleanup + exit, and also frees something it didn't clearly own */
static char *line_or_die(char *line, t_app *app)
{
    if (!line)
    {
        free(line);               // pointless here, but imagine more complex cases
        destroy_app(app, 1);      // exits the whole program
    }
    return line;
}

int main(void)
{
    t_app	app;
	char 	*line;

	app.buffer = malloc(100);
    if (!app.buffer)
        return 1;

    line = read_line();
    line = line_or_die(line, &app);

    /* In a real program we'd use line here... */
    free(line);
    destroy_app(&app, 0);
}
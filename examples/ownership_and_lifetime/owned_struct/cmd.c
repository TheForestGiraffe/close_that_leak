#include "cmd.h"
#include <stdlib.h>

/* -------- local helpers -------- */

static size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}

static size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    if (size == 0)
        return (ft_strlen(src));
    i = 0;
    while (src[i] && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}

static char *ft_strdup(const char *src)
{
    size_t size;
    char *dup;

    size = ft_strlen(src) + 1;
    dup = (char *)malloc(size);
    if (!dup)
        return (NULL);
    ft_strlcpy(dup, src, size);
    return (dup);
}

/* -------- lifecycle -------- */

void    cmd_init(t_cmd *cmd)
{
    if (!cmd)
        return ;
    cmd->path = NULL;
    cmd->argv = NULL;
}

void    cmd_destroy(t_cmd *cmd)
{
    int i;

    if (!cmd)
        return ;
    free(cmd->path);
    if (cmd->argv)
    {
        i = 0;
        while (cmd->argv[i])
            free(cmd->argv[i++]);
        free(cmd->argv);
    }
    free(cmd);
}

/* -------- constructor -------- */

t_cmd   *cmd_create_demo(void)
{
    t_cmd *cmd;

    cmd = (t_cmd *)malloc(sizeof(*cmd));
    if (!cmd)
        return (NULL);
    cmd_init(cmd);

    cmd->path = ft_strdup("/bin");
    if (!cmd->path)
        return (cmd_destroy(cmd), NULL);

    cmd->argv = (char **)calloc(2, sizeof(char *));
    if (!cmd->argv)
        return (cmd_destroy(cmd), NULL);

    cmd->argv[0] = ft_strdup("cmd");
    if (!cmd->argv[0])
        return (cmd_destroy(cmd), NULL);

    return (cmd);
}

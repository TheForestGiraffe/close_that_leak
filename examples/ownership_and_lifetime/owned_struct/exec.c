#include "cmd_types.h"
#include <stdio.h>

/* BORROWS cmd: does not destroy */
int exec_print_borrow(const t_cmd *cmd)
{
    if (!cmd || !cmd->path || !cmd->argv || !cmd->argv[0])
        return (1);
    printf("exec: %s %s\n", cmd->path, cmd->argv[0]);
    return (0);
}

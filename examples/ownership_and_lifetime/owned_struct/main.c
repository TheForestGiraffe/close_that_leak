#include "cmd.h"
#include <stdlib.h>

int exec_print(const t_cmd *cmd);

int main(void)
{
    t_cmd   cmd; // fix - heap or stack?
    int     status;

	cmd_init(&cmd);
	cmd = cmd_create();
	if (!cmd)
        return (EXIT_FAILURE);

    status = exec_print(cmd);
	//...

    cmd_destroy(cmd);

	return (status);
}

// Borrows cmd: does not destroy it
int exec_print(const t_cmd *cmd)
{
    if (!cmd || !cmd->path || !cmd->argv || !cmd->argv[0])
        return (1);
    printf("exec: %s %s\n", cmd->path, cmd->argv[0]);
    return (0);
}
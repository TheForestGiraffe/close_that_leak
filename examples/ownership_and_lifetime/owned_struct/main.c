#include "cmd.h"
#include <stdlib.h>

/* Implemented in exec.c */
int exec_print_borrow(const t_cmd *cmd);

int main(void)
{
    t_cmd   *cmd;
    int     status;

    cmd = cmd_create_demo();
    if (!cmd)
        return (EXIT_FAILURE);

    status = exec_print_borrow(cmd);

    cmd_destroy(cmd);

    /*
     * Ownership transfer example:
     *
     * status = exec_print_consume(cmd);
     * cmd = NULL;
     */

    return (status ? EXIT_FAILURE : EXIT_SUCCESS);
}

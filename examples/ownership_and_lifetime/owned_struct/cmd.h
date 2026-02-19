#ifndef CMD_H
# define CMD_H

# include "cmd_types.h"

void    cmd_init(t_cmd *cmd);
t_cmd   *cmd_create_demo(void);
void    cmd_destroy(t_cmd *cmd);

#endif

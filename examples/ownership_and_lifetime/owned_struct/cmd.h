#ifndef CMD_H
# define CMD_H

typedef struct s_cmd
{
	char	*path;
	char	**argv;
}   t_cmd;

void    cmd_init(t_cmd *cmd);
t_cmd   *cmd_create(void);
void    cmd_destroy(t_cmd *cmd);

#endif

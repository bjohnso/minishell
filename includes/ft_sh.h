# ifndef FT_SH_H
# define FT_SH_H

#include "libft.h"

//Artifacts
typedef struct      s_shell
{
    bool            exit;
}                   t_shell;

typedef struct      s_token
{
    char            *lexeme;
    char            *type;
    int             pos;
}                   t_token;

typedef struct      s_token_list
{
    t_token         *tokens;
    int             size;
}                   t_token_list;

typedef struct      s_buffer
{
    char            *str;
    int             size;
}                   t_buffer;

typedef struct      s_agent
{
    char            *alias;
    const char      *target;
    char            *options;
    char            **files;
    bool            execution_status;
}                   t_agent;

//Shell
t_shell             *new_shell();

//Parser
char                *lexer(char *str);
t_token_list        *parser(t_agent *approved_agent, char *str);

//Token
t_token             *generate_token(t_agent *approved_agent, char  *lexeme, int pos);
t_token             *new_token(char  *lexeme, int pos, char *type);
t_token_list        *new_token_list();
void                token_list_push(t_token_list *token_list, t_token *token);

//Input Reader
char                *input_reader();

//Buffer
t_buffer            *new_buffer();
void                buffer_push(t_buffer *buffer, char c);

//Executor Manager
void                compute_execute(t_agent *approved_agent, t_token_list *token_list);

//Agent
t_agent             *new_agent(char *alias);
const char          *agent_map_target(char *alias);
void                agent_options_push(t_agent *agent, char option);
void                agent_files_push(t_agent *agent, char *file);

#endif
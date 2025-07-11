#ifndef LEXER_TYPES_H
# define LEXER_TYPES_H

# include <stdlib.h>
# include <stdbool.h>

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_REDIR_HEREDOC,
	TOKEN_ENV_VAR,
	TOKEN_EXIT_STATUS,
	TOKEN_SINGLE_QUOTE,
	TOKEN_DOUBLE_QUOTE,
	TOKEN_EOF,
	TOKEN_ERROR
}	t_token_type;

typedef struct s_position
{
	int	line;
	int	column;
}	t_position;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	t_position		position;
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	char		*input;
	size_t		pos;
	size_t		length;
	t_position	current_pos;
	bool		has_error;
	char		*error_msg;
}	t_lexer;

#endif

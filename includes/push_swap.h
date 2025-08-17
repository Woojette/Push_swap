#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_ps
{
	int		arg;
	int		arg2;
	int		error;
	int		atoi_av1;
}	t_ps;

typedef struct s_pile
{
	int		content;
	struct s_pile	*next;
}	t_pile;

t_pile	*ft_lstnew(int	content);
void	ft_lstadd_back(t_pile **lst, t_pile *new);
void	ft_lst_clear(t_pile **lst);

#endif

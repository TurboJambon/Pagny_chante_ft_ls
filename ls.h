/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:15:46 by David             #+#    #+#             */
/*   Updated: 2017/04/06 14:37:43 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include "libft.h"
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define NB_OPTIONS 5
#define OPTIONS "Rtrla"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[1;96m"
#define WHT   "\x1B[37m"
#define RESET "\e[0m"

typedef struct s_options {
	int R;
	int t;
	int r;
	int l;
	int a;
} t_options;

typedef struct s_stock {
	time_t 	time;
	char 	*name;
} 				t_stock;


typedef struct s_dir
{
	unsigned char 	type;
	char			*name;
	time_t			time;
	mode_t			mode;
}				t_dir;

t_options 	create_struct();
int			add_option(char c, t_options *options);
int 		get_options(char **av, t_options *options);
void		printerr(char *arg, int err);
void		freedir(t_dir *tab);
char		*ft_strjoinspe(char const *s1, char const *s2);
int			ft_dirlen(DIR *dir, t_options options);
t_dir		*ft_folder(t_options options, char *path, int len);
void		ft_putdate(char const *str);
t_dir		*ft_tsort(t_dir *folder, int len);
t_dir		*ft_optiont(t_dir *folder, char *path, int a, int len);
void		ft_optl(t_dir folder, char *av);
void		ft_blocks(char *path, int a, t_dir *folder);
void		ft_mode(mode_t n);




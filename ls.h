/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:15:46 by David             #+#    #+#             */
/*   Updated: 2017/05/08 17:56:26 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H
# include <dirent.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include "libft.h"
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>

# define OPTIONS "Rafglprtu"
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[1;96m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"
# define OPT 	t_options
# define ERR_JSP 20

typedef unsigned long int		t_ulint;
typedef unsigned char			t_uchar;
typedef struct		s_options {
	int		r2;
	int		t;
	int		r;
	int		l;
	int		a;
	int		i;
	int		u;
	int		f;
	int		g;
	int		p;
	int		mult;
	size_t	len;
}					t_options;

typedef struct		s_stock {
	time_t	time;
	char	*name;
}					t_stock;

typedef struct		s_dir
{
	unsigned char	type;
	char			*name;
	time_t			time;
	mode_t			mode;
}					t_dir;

t_options			create_struct();
int					puterr(char *s);
int					add_option(char c, t_options *options);
int					get_options(char **av, t_options *options);
void				printerr(char *arg, int err, int flaf);
void				freedir(t_dir *tab);
char				*ft_strjoinspe(char const *s1, char const *s2);
int					ft_dirlen(DIR *dir, t_options options);
t_dir				*ft_folder(t_options options, char *path, int len, int i);
void				ft_putdate(time_t date);
t_dir				*ft_tsort(t_dir *folder, int len);
t_dir				*ft_optiont(t_dir *folder, char *path,
					t_options options, int len);
void				ft_optl(t_dir folder, char *av, t_options options);
void				ft_blocks(char *path, int a, t_dir *folder);
void				ft_mode(mode_t n);
int					ft_affls(t_dir *folder, t_options options, char *av);
void				ft_color(int type, mode_t mode);
void				ft_ls(t_options options, char *av);
int					ft_buf(int fd, void *str, int size);
void				ft_putstr_buf(char *str);
void				ft_putchar_buf(char c);
void				ft_putnbr_buf(int n);
void				ft_putendl_buf_fd(char *str, int fd);
int					ft_buf(int fd, void *str, int size);
void				ft_putdate(time_t date);
void				printl(struct stat stats, int type, char *name,
					t_options options);
void				options_r(t_options options, t_dir *folder,
					char *av, char *path);
void				printmult(char *av);
t_dir				*ft_sort_dirname(t_dir *folder, size_t len);
void				lsfile(char *av, t_options options);
void				ft_sort_spe(char **tab, int ac, int k, t_options options);
char				*getpath(char *path);
t_dir				*ft_sort_dirname(t_dir *folder, size_t len);
void				ft_putstr_buf_fd(char *str, int fd);
void				multnewline(t_options options);
t_dir				*ft_optionu(t_dir *folder, char *path, int a, int len);
void				del_options(t_options *options);
void				ft_putchar_buf_fd(char c, int fd);
void				ft_putcharendl_buf_fd(char c, int fd);
void				printtype(int type);
int					typestat(struct stat stats);

#endif

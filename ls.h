/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:15:46 by David             #+#    #+#             */
/*   Updated: 2017/03/30 23:50:32 by niragne          ###   ########.fr       */
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
#define NB_OPTIONS 5
#define OPTIONS "Rtrla"
#include <errno.h>

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

t_options create_struct();
int		add_option(char c, t_options *options);
int get_options(char **av, t_options *options);
void	printerr(char *arg, int err);
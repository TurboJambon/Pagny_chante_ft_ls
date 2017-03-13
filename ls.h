/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David <David@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:15:46 by David             #+#    #+#             */
/*   Updated: 2017/03/13 18:01:52 by David            ###   ########.fr       */
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
#define NB_OPTIONS 5
#define OPTIONS "Rtrla"

typedef struct s_options {
	int R;
	int t;
	int r;
	int l;
	int a;
} t_options;

t_options create_struct();
int		add_option(char c, t_options *options);
int get_options(char **av, t_options *options);
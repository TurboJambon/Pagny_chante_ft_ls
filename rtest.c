/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:03:44 by dchirol           #+#    #+#             */
/*   Updated: 2017/03/19 16:05:17 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ls(DIR *dir, t_options options, char *av)
{
	struct dirent 	*read;

	while ((read = readdir(dir)))
	{
		if ((read->d_name[0] == '.' && options.a == 1)
			|| options.a == 1 || (options.a == 0 && read->d_name[0] != '.'))
		{
			if (options.l)
				ft_optl(read, options, av);
			ft_putstr(read->d_name);
			if (options.l)
				ft_putchar('\n');
			else
				ft_putchar('\t');
		}	
	}
}

int main(int ac, char **av)
{
	DIR 	*dir;
	t_options options;
	int i;

	options = create_struct();
	i = get_options(av, &options);
	if (i == ac)
	{
		dir = opendir(".");
		ft_ls(dir, options, ".");
	}
	while (av[i])
	{
		dir = opendir(av[i]);
		ft_ls(dir, options, av[i]);
		ft_putstr("\n -- \n");
		i++;
	}
	ft_putchar('\n');
	closedir(dir);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:45:57 by slynell           #+#    #+#             */
/*   Updated: 2020/08/17 19:07:21 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int		check_n(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_parsing(char **s, char **line)
{
	int		i;
	char	*tmp;

	if ((i = check_n(*s)) == -1)
		i = ft_strlen(*s);
	*line = ft_strsub(*s, 0, i);
	tmp = *s;
	*s = ft_strsub(*s, i + 1, ft_strlen(*s) - i);
	free(tmp);
	return (1);
}

static void		ft_strjoin_del(char **s, char *buff)
{
	char *tmp;

	tmp = *s;
	*s = ft_strjoin(*s, buff);
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[MAX_FD_COUNT];
	char		buffer[BUFF_SIZE_GNL + 1];
	int			ret;

	if (fd < 0 || !line || fd >= MAX_FD_COUNT)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	if (check_n(s[fd]) != -1)
		return (ft_parsing(&s[fd], line));
	while (check_n(s[fd]) == -1)
	{
		ret = read(fd, buffer, BUFF_SIZE_GNL);
		if (ret <= 0)
			break ;
		buffer[ret] = 0;
		ft_strjoin_del(&s[fd], buffer);
	}
	if (ret < 0)
		return (-1);
	if (check_n(s[fd]) != -1)
		return (ft_parsing(&s[fd], line));
	*line = s[fd];
	return (!ret && (!s[fd] || !*s[fd]) ? 0 : !(s[fd] = 0));
}

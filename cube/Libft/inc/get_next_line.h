/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:56:35 by vimercie          #+#    #+#             */
/*   Updated: 2022/03/23 17:32:36 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 20

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

char	*get_next_line(int fd);
int		newline_chr(char *s, int start);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);

#endif
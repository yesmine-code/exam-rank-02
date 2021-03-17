#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str != NULL)
	{
		while (i < ft_strlen(s1))
		{
			str[i] = s1[i];
			i++;
		}
		while (j < ft_strlen(s2))
		{
			str[i] = s2[j];
			i++;
			j++;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(*dest) * (ft_strlen(s) + 1));
	i = 0;
	if (dest != NULL)
	{
		while (s[i] != '\0')
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char *s,int start, int len)
{
	char	*ptr;
	int	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	i = 0;
	ptr = malloc(sizeof(*ptr) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*append_buf(int fd, char *buf, int *bytes_read, int buffer_size)
{
	char	tmp[buffer_size+ 1];
	char	*result;

	result = NULL;
	tmp[0] = 0;
    *bytes_read = read(fd, tmp, buffer_size);
	if (*bytes_read > 0)
	{
        tmp[*bytes_read] = '\0';
		if (buf == NULL)
			result = ft_strdup(tmp);
		else
		{
			result = ft_strjoin(buf, tmp);
			free(buf);
		}
		buf = result;
	}
	return (buf);
}

int		ft_case_0(char **buf, char **line)
{
	if (!*buf)
	{
		*line = ft_strdup("");
	}
	else
	{
		*line = ft_strdup(*buf);
		free(*buf);
		*buf = NULL;
	}
	return (0);
}

int		get_next_line(char **line)
{
	static char	*buf;
	char		*tmp;
	int			bytes_read;
	int			line_length;
    int         fd;
    int         buffer_size;

    fd = 0;
    buffer_size = 200;
	if (line == NULL)
		return (-1);
	while (buf == NULL || (!(ft_strchr(buf, '\n'))))
	{
		buf = append_buf(fd, buf, &bytes_read, buffer_size);
		if (bytes_read == 0)
			return (ft_case_0(&buf, line));
		else if (bytes_read == -1)
		{
			free(buf);
			return (-1);
		}
	}
	line_length = ft_strchr(buf, '\n') - buf;
	*line = ft_substr(buf, 0, line_length);
	tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
	free(buf);
	buf = tmp;
	return (1);
}
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct  s_flags
{
	int minimal_size;
	int precision;
	int precision_exist;
	char sign;
	char specifier;
}		t_flags;

int		ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*ptr;
	int		i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < (int)start)
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

int	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return(0);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
    return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

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

int		ft_count(long long n, char *base)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n / ft_strlen(base) != 0)
	{
		i++;
		n = n / ft_strlen(base);
	}
	return (i + 1);
}

char	*ft_itoa(long long nbr, char *base)
{
	char	*str;
	int		length;
	int		tmp;

	length = ft_count(nbr, base);
	tmp = length;
	str = malloc(sizeof(char) * (length + 1));
	if (str != NULL)
	{
		if (nbr < 0)
		{
			str[0] = '-';
			nbr = nbr * -1;
		}
		while (nbr / ft_strlen(base) != 0 && length >= 0)
		{
			str[length - 1] = base[nbr % ft_strlen(base)];
			nbr = nbr / ft_strlen(base);
			length--;
		}
		str[length - 1] = base[nbr];
		str[tmp] = '\0';
	}
	return (str);
}

int		ft_atoi(char *ptr)
{
	int				sign;
	long long int	result;
	int				i;

	sign = 1;
	result = 0;
	i = 0;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(ptr[i]) == 1)
	{
		result = result * 10 + (ptr[i] - '0');
		i++;
	}
	return (sign * result);
}

char	*read_arg(t_flags *flags, va_list list)
{
	char	*s;
    int arg;

	if (flags->specifier == 'd')
    {
        arg = va_arg(list, int);
        if (arg < 0)
        {
            flags->sign = '-';
            arg = -arg;
        }
		return (ft_itoa(arg, "0123456789"));
    }
	if (flags->specifier == 'x')
		return (ft_itoa(va_arg(list, unsigned int), "0123456789abcdef"));
	if (flags->specifier == 's')
		return (ft_strdup((s = va_arg(list, char *)) ? s : "(null)"));
	return (NULL);
}

char    *apply(char *str, int min, char c)
{
    int l;
    char *s;
    char *tmp;
    int i;

    l = ft_strlen(str);
    if (l < min)
    {
        s = malloc(sizeof(char *) * (min - l + 1));
        i = 0;
        while (i < min - l)
        {
            s[i] = c;
            i++;
        }
        s[i] = '\0';
        tmp = ft_strjoin(s, str);
        free(s);
		free(str);
        return (tmp);
    }
    else
	{
		s = ft_strdup(str);
		free(str);
	    return s;
	}
}

int	ft_parse(const char *format,t_flags *f, int *i)
{
    int     begin;
    char    *str;

    begin = 0;
    if (ft_isdigit(format[*i]) == 1)
    {
        begin = *i;
        *i = *i + 1;
        while (ft_isdigit(format[*i]) == 1)
              *i = *i + 1;
        str = ft_substr((char *)format, begin, *i - begin);
        f->minimal_size = ft_atoi(str);
        free(str);
    }
    begin = 0;
	if (format[*i] == '.')
	{
		*i = *i + 1;
        f->precision_exist = 1;
		if (ft_isdigit(format[*i]) == 1)
        {
            f->precision_exist = 1;
            begin = *i;
            *i = *i + 1;
            while (ft_isdigit(format[*i]) == 1)
              *i = *i + 1;
            str = ft_substr((char *)format, begin, *i - begin);
            f->precision = ft_atoi(str);
            free(str);
        }
	}
	if(format[*i] =='s' || format[*i] == 'd' || format[*i] == 'x')
		f->specifier = format[*i];
   	if (f->specifier == 0)
   	     return(0);
	return(1);
}

char *format_arg(t_flags flags, va_list list)
{
    char    *s;
    char *str;

    str = read_arg(&flags, list);
    if (flags.specifier == 's')
    {
        if (flags.precision_exist == 1)
        {
            if (flags.precision == 0)
                s = ft_strdup("");
            else
                s = ft_substr(str, 0, flags.precision);
            free(str);
            return(apply(s, flags.minimal_size, ' '));
        }
        return(apply(str, flags.minimal_size, ' '));
    }
    else
    {
        if (flags.precision_exist == 1)
            s = apply(str, flags.precision, '0');
        else
		{
            s = ft_strdup(str);
        	free(str);
		}
        if (flags.sign == '-')
        {
            str = ft_strjoin("-\0", s);
            free(s);
            return (apply(str, flags.minimal_size, ' '));
        }
        return (apply(s, flags.minimal_size, ' '));
    }
}

int		ft_printf(const char *format, ...)
{
	va_list	list;
	t_flags	flags;
	int		i;
	int		compteur;
	int		ret;
    char *str;

	i = 0;
	compteur = 0;
	flags.minimal_size = 0;
	flags.precision = 0;
	flags.precision_exist = 0;
    	flags.specifier = 0;
    	flags.sign = ' ';
	va_start(list, format);
	while (format[i] != '\0' && compteur >= 0)
	{
		if (format[i] == '%')
		{
			i++;
			ret = ft_parse(format,&flags, &i);
            i++;
            if (ret == 0)
                return (0);
            str = format_arg(flags, list);            
            compteur += ft_putstr(str);
            free(str);
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			compteur++;
}
	}
	va_end(list);
	return (compteur);
}

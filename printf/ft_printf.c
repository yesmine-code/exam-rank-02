#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_flags
{
	int minimal_size;
	int precision;
	int precision_exist;
	char sign;
	char specifier;
}		t_flags;

int ft_strlen(char *s)
{
	int i;
	i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}

int ft_isdigit(char c)
{
	if(c <= '9' && c >= '0')
		return 1;
	return 0;
}

char *ft_strdup(char *s)
{
	char *str;
	int i;
	i = 0;
	str = malloc(sizeof(char*)*(ft_strlen(s) + 1 ));
	if(str != NULL)
	{
		while(s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return str;
}

char *ft_substr(char *s, int start, int len)
{
	int i;
	char *str;
	i = 0;
	if(s == NULL)
		return NULL;
	if(start > ft_strlen(s))
		return(ft_strdup(""));
	str = malloc(sizeof(char *) * (len + 1));
	if(str != NULL)
	{
		while(i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	return str;
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i;
	int j;
	i = 0;
	j = 0;
	if(!s1 || !s2)
		return NULL;
	str = malloc(sizeof(char *)*(ft_strlen(s1) + ft_strlen(s2) + 1));
	if(str != NULL)
	{
		while(s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while(s2[j] != '\0')
		{
			str[i] = s2[j];
			i++;
			j++;
		}
		str[i] = '\0';
	}
	return str;
}

int ft_putstr(char *s)
{
	int i;
	i = 0;
	if (s == NULL)
		return 0;
	while(s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return i;
}

int ft_atoi(char *s)
{
	int result ;
	int sign;
	int i;

	sign = 1;
	result = 0;
	i = 0;
	if(s[0] == '-' || s[0] == '+')
	{
		if(s[0] == '-')
			sign = sign * -1;
		i++;
	}
	while(s[i] != '\0')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return(result * sign);
}
int ft_count(long long n, char *base)
{
	int i;
	i = 0;
	if(n < 0)
		i++;
	while(n / ft_strlen(base) != 0)
	{
		i++;
		n = n/ ft_strlen(base);
	}
	return (i + 1);
}

char *ft_itoa(long long n, char *base)
{
	char *str;
	int l;
	int tmp;

	l = ft_count(n, base);
	tmp = l;
	str = malloc(sizeof(char *) * (l + 1));
	if(str != NULL)
	{
		if(n < 0)
		{
			str[0] = '-';
			n = n * -1;
		}
		while(n / ft_strlen(base) != 0)
		{
			str[l - 1] = base[n % ft_strlen(base)];
			l--;
			n = n /ft_strlen(base);
		}
		str[l - 1] =  base[n];
		str[tmp] = '\0';
	}
	return str;
}

char *apply(char *s, int min, char c)
{
	int i ;
	char *str;
	char *tmp;
	i = 0;

	tmp = NULL;
	if(min > ft_strlen(s))
	{
		str = malloc(sizeof(char *) *(min - ft_strlen(s) + 1));
		if(str != NULL)
		{
			while(i < min - ft_strlen(s))
			{
				str[i] = c;
				i++;
			}
			str[i] = '\0';
			tmp = ft_strjoin(str, s);
			free(s);
			free(str);
		}
		return tmp;

	}
	else
	{
		str = ft_strdup(s);
		free(s);
		return str;
	}
}
char *get_arg(va_list list, t_flags *f)
{
	int arg;
unsigned int r;
	char *s;

	if(f->specifier == 'd')
	{
		arg = va_arg(list, int);
		if(arg < 0 && arg > -2147483648 && arg <= 2147483647)
		{
			f->sign = '-';
			arg = arg * -1;
		}
		if(arg == 0 && f->precision_exist == 1)
			return(ft_strdup(""));
		return(ft_itoa(arg, "0123456789"));
	}
	if(f->specifier == 'x')
	{
		r = va_arg(list,unsigned  int);
		if(r == 0 && f->precision_exist == 1)
			return(ft_strdup(""));
		return(ft_itoa(r, "0123456789abcdef"));
	}
	if(f->specifier == 's')
	{
		s = va_arg(list, char *);
		if(s == NULL)
		{
			if(f->precision >= ft_strlen("(null)") || f->precision_exist == 0)
				return (ft_strdup("(null)"));
			else
				return (ft_strdup(""));
		}
		else
			return(ft_strdup(s));
	}
	return NULL;
}

char *format_arg(va_list list, t_flags *f)
{
	char *str;
	char *s;

	str = get_arg(list, f);
	if(f->specifier == 's')
	{
		if(f->precision_exist == 1)
		{
			if(f->precision == 0)
				s = ft_strdup("");
			else
				s = ft_substr(str, 0, f->precision);
			free(str);
			return(apply(s, f->minimal_size, ' '));
		}
		return(apply(str, f->minimal_size, ' '));
	}
	else
	{
		if(f->precision_exist == 1)
			s = apply(str, f->precision, '0');
		else
		{
			s = ft_strdup(str);
			free(str);
		}
		if(f->sign == '-')
		{
			str = ft_strjoin("-\0", s);
			free(s);
			return(apply(str, f->minimal_size, ' '));
		}
		return(apply(s, f->minimal_size, ' '));
	}
}

int ft_parse(char *format, t_flags *f, int *i)
{
	int begin;
	char *str;

	if(ft_isdigit(format[*i]) == 1 || format[*i] == '-')
	{
		begin = *i;
		*i = *i + 1;
		while(ft_isdigit(format[*i]) == 1)
			*i = *i + 1;
		str = ft_substr(format, begin, *i -begin);
		f->minimal_size = ft_atoi(str);
		if(f->minimal_size < 0)
			f->minimal_size = 0;
		free(str);
	}
	if(format[*i] == '.')
	{
		f->precision_exist = 1;
		*i = *i + 1;
		if(ft_isdigit(format[*i]) == 1)
		{
			begin = *i;
			*i = *i + 1;
			while(ft_isdigit(format[*i]) == 1)
				*i = *i + 1;
			str = ft_substr(format, begin, *i - begin);
			f->precision = ft_atoi(str);
			free(str);
		}
	}
	if(format[*i] == 's' || format[*i] == 'd' || format[*i] == 'x')
		f->specifier = format[*i];
	if(f->specifier == 0)
		return 0;
	return 1;
}


int ft_printf(const char *format, ...)
{
	int ret;
	int i;
	int compteur;
	t_flags f;
	va_list list;
	char *str;

	i = 0;
	compteur = 0;

	va_start(list, format);
	while(format[i] != '\0')
	{
		if(format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			i = i + 2;
			compteur++;
		}
		else if(format[i] == '%')
		{
			i++;
			f.minimal_size = 0;
			f.precision = 0;
			f.specifier = 0;
			f.sign = ' ';
			f.precision_exist = 0;
			ret = ft_parse((char*)format, &f, &i);
			i++;
			if(ret == 0)
				return 0;
			str = format_arg(list, &f);
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
	return compteur;
}


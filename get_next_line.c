#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return(i);
}

char *ft_newstr(size_t n)
{
	void	*d;

	if ((d = malloc(sizeof(char) * (n + 1))))
	    *((char *)d + n) = '\0';
	return ((char *)d);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *d1, *d2, *bgn, *tmp;

	d1 = s1;
	d2 = s2;
	if (!d1 && !d2)
		return (NULL);
	if ((bgn = ft_newstr((d1 ? ft_strlen(d1) : 0) + (d2 ? ft_strlen(d2) : 0))))
		tmp = bgn;
	if (d1)
		while (*d1)
			*tmp++ = *d1++;
	if (d2)
		while (*d2)
			*tmp++ = *d2++;
	return (bgn);
}

int get_next_line(char **line)
{
    char buf[2];
	char *del;
	int rd;

	if (!line)
		return (-1);
    buf[1] = '\0';
	*line = (char *)malloc(1);
	**line = '\0';
    while ((rd = read(0, buf, 1)) > 0)
    {
		if (*buf == '\n')
            *buf = '\0';
		del = *line;
        *line = ft_strjoin(*line, buf);
		free(del);
		if (*buf == '\0')
			return(1);
    }
    return(rd);
}

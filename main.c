#include "so_long.h"
#include "./gnl/get_next_line.h"

// char	*replace_zeroes_with_space(char **line)
// {
// 	char	*newline;
// 	int		i;

// 	if (*line == NULL)
// 		return (NULL);
// 	i = 0;
// 	newline = (char *)malloc(ft_strlen(*line) * sizeof(char) + 1);
// 	while (!((*line)[i] == '\0' || (*line)[i] == '\n'))
// 	{
// 		if ((*line)[i] == '0')
// 			newline[i] = ' ';
// 		else
// 			newline[i] = (*line)[i];
// 		i++;
// 	}
// 	newline[i] = '\0';
// 	// free(*line);
// 	return (newline);
// }

int	main(void)
{
	// int fd = open("./maps/minimal.ber", O_RDONLY);
	read_file("./maps/minimal.ber");
	// char *line;

	// line = get_next_line(fd);
	// line = get_next_line(fd);
	// printf("%s", replace_zeroes_with_space(&line));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:32:21 by vivaz-ca          #+#    #+#             */
/*   Updated: 2025/04/26 15:21:46 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* //MAIN FUNCTION FOR A FILE
int main(void)
{
    int fd;
    char *line;

    fd = open("teste.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    printf("--- Reading/Printing file---\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
*/
/* //MAIN FUNCTION FOR THE INPUT TERMINAL
int main(void)
{
    char    *line;

    while (1)
    {
        line = get_next_line(0);
        if (!line)
            break ;
		printf("You wrote: %s", line);
        free(line);
    }
    return (0);
}
*/

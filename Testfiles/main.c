/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:31:05 by smago             #+#    #+#             */
/*   Updated: 2020/10/23 20:40:11 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int  main(void)
{
	char src[100] = "Hello World";
	char dest[100];
	char *str;
	// ft_strlen
	printf("\nft_strlen___________________\n\n");

    int i = ft_strlen(src);
	int x = strlen(src);
	printf("m - %d o - %d\n", i, x);
    i = ft_strlen("");
	x = strlen("");
	printf("m - %d o - %d\n", i, x);

	// ft_strcpy
	printf("\nft_strcpy __________________\n\n");

	str = ft_strcpy(dest, "");
	printf("m - %s %s\n", dest, str);
	str = strcpy(dest, "");
	printf("o - %s %s\n", dest, str);

	str = ft_strcpy(dest, src);
	printf("m - %s %s\n", dest, str);
	str = strcpy(dest, src);
	printf("o - %s %s\n", dest, str);


	// ft_strcmp
	printf("\nft_strcmp___________________\n\n");

	i = ft_strcmp(dest, src);
	x = strcmp(dest, src);
	printf("m - %d o - %d\n", i, x);

	char t[100] = "Hellz";
	i = ft_strcmp(dest, t);
	x = strcmp(dest, t);
	printf("m - %d o - %d\n", i, x);

	char dest1[100] = "";
	char src1[100] = "";
	i = ft_strcmp(dest1, src1);
	x = strcmp(dest1, src1);
	printf("m - %d o - %d\n", i, x);

	i = ft_strcmp(dest1, t);
	x = strcmp(dest1, t);
	printf("m - %d o - %d\n", i, x);

	i = ft_strcmp(t, dest1);
	x = strcmp(t, dest1);
	printf("m - %d o - %d\n", i, x);

	//ft_read
	printf("\nft_read_____________________\n\n");

	char destr[100];
	int fd = open("Testfiles/test", O_RDWR | O_CREAT, 0666);
	i = ft_read(fd, destr, 20);
	destr[i] = '\0';
	printf("m - %s\n", destr);
	close(fd);

	fd = open("Testfiles/test", O_RDWR | O_CREAT, 0666);
	x = read(fd, destr, 20);
	destr[x] = '\0';
	printf("o - %s\n", destr);
	close(fd);
	printf("m - %d o - %d\n", i, x);

	fd = open("Testfiles/test1", O_RDWR | O_CREAT, 0666);
	i = ft_read(fd, destr, 20);
	printf("%s\n", strerror(errno));
	close(fd);

	fd = open("Testfiles/test1", O_RDWR | O_CREAT, 0666);
	x = read(fd, destr, 20);
	printf("%s\n", strerror(errno));
	close(fd);
	printf("m - %d o - %d\n", i, x);

	i = ft_read(1, destr, 20);
	destr[i] = '\0';
	printf("m - %s\n", destr);
	x = read(1, destr, 20);
	destr[x] = '\0';
	printf("o - %s\n", destr);

	
	//ft_write ft_strlen
	printf("\nft_write ft_strlen__________\n\n");

	i = ft_write(1, src, ft_strlen(src));
	ft_write(1, "\n", 1);
	x = write(1, src, strlen(src));
	write(1, "\n", 1);
	printf("m - %d o - %d\n", i, x);
	i = ft_write(-10, "m - Done\n", 9);
	printf("%s\n", strerror(errno));
	x = write(-10, "o - Done\n", 9);
	printf("%s\n", strerror(errno));
	printf("m - %d o - %d\n", i, x);

	fd = open("Testfiles/test", O_RDWR | O_CREAT, 0666);
	i = ft_write(fd, "Hello\n", 6);
	x = write(fd, "Hello\n", 6);
	printf("m - %d o - %d\n", i, x);
	close(fd);

	//ft_strdup
	printf("\nft_strdup___________________\n\n");
	char new[100] = "I will allocate memory and copy string";
	char *str1 = ft_strdup(new);
	char *str2 = strdup(new);
	printf("m - %s\no - %s\n", str1, str2);

	str1 = ft_strdup(dest1);
	str2 = strdup(dest1);
	printf("m - %s\no - %s\n", str1, str2);

    return (0);
}


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smago <smago@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/23 17:34:19 by smago             #+#    #+#              #
#    Updated: 2020/10/23 20:42:31 by smago            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s 

OBJ = $(SRCS:.s=.o)

FLAGS = nasm -fmacho64

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.s
	$(FLAGS) $< -o $@

clean: 
	rm -f $(OBJ)
		
fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

test: $(NAME)
	gcc -Wall -Wextra -Werror Testfiles/main.c -L. -lasm $(NAME)
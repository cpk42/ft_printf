#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/20 15:48:29 by ckrommen          #+#    #+#              #
#    Updated: 2018/02/21 16:20:42 by ckrommen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = tools.c ft_printf.c convert.c flags.c numberconv.c helper.c buffer.c

FLAGS = -g -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT = libft/*.c

OBJS = *.o

$(NAME):
	@echo "\033[32mCompiling source files\033[0m"
	@gcc $(FLAGS) -c $(SRCS) $(LIBFT)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@echo "\033[32mCleaning up\033[0m"
	@rm -rf $(OBJS)

fclean: clean
	@echo "\033[32mFull clean\033[0m"
	@rm -rf $(NAME)

re: fclean all
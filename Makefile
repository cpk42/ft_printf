#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/20 15:48:29 by ckrommen          #+#    #+#              #
#    Updated: 2018/01/20 15:55:57 by ckrommen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = tools.c ft_printf.c convert.c

FLAGS = -Wall -Wextra -Werror

NAME = printf

LIBFT = ./libft/

$(NAME):
		@$(MAKE) -C $(LIBFT)
		@gcc $(FLAGS) $(SRCS) -L$(LIBFT) -lft -o $(NAME)

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT)
	rm -rf $(NAME)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)

re: fclean all
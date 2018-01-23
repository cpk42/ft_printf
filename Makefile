#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/20 15:48:29 by ckrommen          #+#    #+#              #
#    Updated: 2018/01/22 21:07:18 by ckrommen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = tools.c ft_printf.c convert.c flags.c main.c numberconv.c helper.c

FLAGS = -Wall -Wextra -Werror

NAME = printf

LIBFT = ./libft/

$(NAME):
	@echo "Make Libft"
	@$(MAKE) -C $(LIBFT)
	@echo "Compiling source files"
	@gcc $(FLAGS) $(SRCS) -L$(LIBFT) -lft -o $(NAME)

all: $(NAME)

clean:
	@echo "Cleaning up"
	@$(MAKE) clean -C $(LIBFT)
	@rm -rf $(NAME)

fclean: clean
	@echo "Full clean"
	@$(MAKE) fclean -C $(LIBFT)

re: fclean all
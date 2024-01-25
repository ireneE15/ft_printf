# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iescalon <iescalon@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 10:40:51 by iescalon          #+#    #+#              #
#    Updated: 2024/01/25 09:52:23 by iescalon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_char_str.c ft_nbr.c ft_printf.c ft_puthex.c ft_putptr.c
OBJS			= $(SRCS:.c=.o)

CC				= @CC
RM				= @rm -fr
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
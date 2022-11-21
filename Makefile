# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #lldb
#    By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:54:12 by jflorido          #+#    #+#            #   Updated: 2022/11/01 14:28:44 by jflorido         ###   ########.fr       #  #   # #
#                                                                              #
# **************************************************************************** #

NAME = ft_gnl.a

SRC = 	get_next_line.c get_next_line_utils.c

#SRC_Bonus =

OBJS = $(SRC:.c=.o)
#OBJS_Bonus = $(SRC_Bonus:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR      = ar
AFLAG   = -rc

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(AFLAG) $(NAME) $^

#bonus: $(OBJS) $(OBJS_Bonus)
#	$(AR) $(AFLAG) $(NAME) $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

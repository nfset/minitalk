# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 13:44:24 by apieniak          #+#    #+#              #
#    Updated: 2025/02/11 17:15:05 by apieniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client
CFLAGS = -Wall -Wextra -Werror -I(LIBFT)

PRINTF_PATH = ft_printf
CLIENT_FILES = client.c
SERVER_FILES = server.c
CC = cc
RM = rm -f
CLIENT_OBJ = $(CLIENT_FILES:.c=.o)
SERVER_OBJ = $(SERVER_FILES:.c=.o)

LIBFTPRINTF = $(PRINTF_PATH)/libftprintf.a

all: $(NAME)

server: $(SERVER_OBJ) $(LIBFTPRINTF)
        $(CC) $(SERVER_OBJ) -L$(PRINTF_PATH) -\ft_printf -o $@

client: $(CLIENT_OBJ) $(LIBFTPRINTF)
        $(CC) $(CLIENT_FILES) -L$(PRINTF_PATH) -\ft_printf -o $@

$(LIBFTPRINTF):
        @make -C $(PRINTF_PATH)

%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        $(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
        @make clean -C $(PRINTF_PATH)

fclean: clean
        $(RM) $(NAME)
        @make fclean -C $(PRINTF_PATH)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
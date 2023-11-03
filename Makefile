# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 17:56:08 by chonorat          #+#    #+#              #
#    Updated: 2023/09/28 12:12:43 by chonorat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLOR
_GREEN = \033[92m
_YELLOW = \033[33m

#POLICE
_END = \033[0m
_BOLD = \033[1m

NAME = Minitalk
CC = @cc
RM = @rm -rf
OBJS_DIR = @mkdir -p Objects
CFLAGS = -Wall -Wextra -Werror
HEADER = Includes/minitalk.h
LIBFT = libft/libft.a
MAKE_LIBFT = @make -C libft
CLEAN_LIBFT = @make clean -C libft
FCLEAN_LIBFT = @make fclean -C libft
PRINT = @echo
FILES = server\
		client
OBJS = $(addsuffix .o, $(addprefix Objects/, $(FILES)))

$(NAME): all

all: server client

server: Objects/server.o
	$(PRINT) "\n${_YELLOW}Checking Libft...${_END}"
	$(MAKE_LIBFT)
	$(PRINT) "\n${_YELLOW}Making server...${_END}"
	$(CC) $< $(LIBFT) -o server
	$(PRINT) "${_BOLD}${_GREEN}Server done.${_END}"

client: Objects/client.o
	$(PRINT) "\n${_YELLOW}Checking Libft...${_END}"
	$(MAKE_LIBFT)
	$(PRINT) "\n${_YELLOW}Making client...${_END}"
	$(CC) $< $(LIBFT) -o client
	$(PRINT) "${_BOLD}${_GREEN}Client done.${_END}"

Objects/%.o: Sources/%.c Makefile $(HEADER)
	$(OBJS_DIR)
	$(PRINT) "\nCompiling ${_BOLD}$<$(_END)..."
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(CLEAN_LIBFT)
	$(PRINT) "\n${_BOLD}Cleaning Objects...${_END}"
	$(RM) $(OBJS)
	$(PRINT) "${_BOLD}${_GREEN}Objects cleaned.${_END}"

fclean:
	$(FCLEAN_LIBFT)
	$(PRINT) "\n${_BOLD}Cleaning Objects...${_END}"
	$(RM) $(OBJS)
	$(PRINT) "${_BOLD}${_GREEN}Objects cleaned.${_END}"
	$(PRINT) "${_BOLD}Deleting executables...${_END}"
	$(RM) server client
	$(PRINT) "${_BOLD}${_GREEN}Executables deleted.${_END}"
	$(PRINT) "${_BOLD}Deleting Objects directory...${_END}"
	$(RM) Objects
	$(PRINT) "${_BOLD}${_GREEN}Objects directory deleted.${_END}"

re: fclean all

.PHONY: all clean fclean re


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 17:15:29 by ptheo             #+#    #+#              #
#    Updated: 2024/06/25 15:57:27 by ptheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = src/

FILES =	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
		ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
		ft_itoa.c ft_memcpy.c  ft_putendl_fd.c  ft_strlcpy.c \
		ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_strrchr.c \
		ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strchr.c \
		ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
		ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

FILES += get_next_line.c get_next_line_utils.c 

FILES += ft_printf.c ft_printf_utils.c ft_print_all.c

vpath %.c $(SRC)

OBJS = $(FILES:.c=.o)

CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/
AR = ar

all: $(NAME)

$(NAME): $(OBJS) 
			$(AR) rcs $(NAME) $(OBJS)

$(OBJ) :
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 16:29:58 by angellop          #+#    #+#              #
#    Updated: 2024/12/28 17:44:07 by angellop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
MY_SOURCES = ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c

B_SOURCES = ft_lstnew.c 		\
			ft_lstadd_front.c 	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c

CC 		= cc

OBJS	= $(MY_SOURCES:.c=.o)
B_OBJS 	= $(B_SOURCES:.c=.o)

RM		= rm -f

LIBC	= ar -rcs

FLAGS	= -fPIC -Wall -Wextra -Werror

INCS	= .

$(NAME): ${OBJS} $(B_OBJS)
	${LIBC} $(NAME) $(OBJS) $(B_OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

bonus: $(OBJS) $(B_OBJS)
	${LIBC} $(NAME) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(bonus)

clean:
	$(RM) -f $(OBJS) $(B_OBJS)

re: fclean all

.PHONY: all bonus clean fclean re .c.o

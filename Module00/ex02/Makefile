# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:26:56 by fgeslin           #+#    #+#              #
#    Updated: 2023/04/07 12:53:20 by fgeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####	CONFIG		############################################################
NAME		:= tests
CC			:= c++
RM			:= rm -f
CFLAGS		= -Wall -Wextra -Werror -std=c++98

#####	SOURCES		############################################################
SRC			=	tests.cpp \
				Account.cpp
OBJ			=	$(SRC:.cpp=.o)

#####	Makefile  objs		###################################################
WHITE		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
CYAN 		:= \033[1;36m

.cpp.o:
	@ echo "$(YELLOW)Compiling: $(WHITE)$<"
	@ ${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

# ------ #

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "$(GREEN)Compilation ${WHITE}of ${CYAN}$(NAME) ${WHITE}..."
	@ $(CC) -o $(NAME) $(OBJ)
	@ echo "$(CYAN)$(NAME) $(GREEN)created$(WHITE) ✔️"

# ------ #

clean:
	@ ${RM} $(OBJ) $(OBJ_BONUS)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(WHITE)objs ✔️"

fclean: clean
	@ ${RM} $(NAME)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(WHITE)binary ✔️"

re: fclean all

.PHONY: all clean fclean re

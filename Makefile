# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 20:05:44 by ldutriez          #+#    #+#              #
#    Updated: 2022/08/16 12:57:24 by ldutriez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		trie_testing

CC 		=		c++

SRC_DIR = 		$(shell find testing -type d)

OBJ_DIR = 		objs

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

SRC 	=		main.cpp

OBJ		=		$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

CFLAGS	=		-Wall -Wextra -Werror

DEBUG =
ifeq ($(DEBUG), fs)
	CFLAGS += -fsanitize=address
	CFLAGS += -g3
	CFLAGS += -O0
	msg = $(shell echo "$(_PURPLE)fsanitize and debug flags are added.$(_WHITE)")
	useless := $(info $(msg))
else ifeq ($(DEBUG), vl)
	CFLAGS += -g3
	CFLAGS += -O0
	msg = $(shell echo "$(_PURPLE)Valgrind and debug flags are added. Take care to rebuild the program entirely if you already used valgrind.$(_WHITE)")
	useless := $(info $(msg))
else ifeq ($(DEBUG), gdb)
	CFLAGS += -g3
	CFLAGS += -O0
	msg = $(shell echo "$(_PURPLE)gdb and debug flags are added.$(_WHITE)")
	useless := $(info $(msg))
else
	CFLAGS += -O3
	msg = $(shell echo "$(_PURPLE)Debug mode not enabled. Optimization flags are added.$(_WHITE)")
	useless := $(info $(msg))
endif

# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all:			$(NAME)

$(NAME):		$(OBJ) Makefile
				@echo "-----\nCompiling $(_YELLOW)$@$(_WHITE) ... \c"
				@$(CC) $(CFLAGS) -I. $< -o $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"
				

show:
				@echo "\nSRC :\n$(SRC)\n"
				@echo "OBJ :\n$(OBJ)\n"
				@echo "CFLAGS :\n$(CFLAGS)\n"
				@echo "IFLAGS :\n$(IFLAGS)\n"
				@echo "LIB_DIR :\n$(LIB_DIR)\n"

$(OBJ_DIR)/%.o : 	%.cpp
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -I. -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

re:				fclean all

clean:
				@echo "Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@rm -rf $(OBJ_DIR)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting library File $(_YELLOW)$(NAME).a $(_WHITE)and executable $(_YELLOW)$(NAME)$(_WHITE) ... \c"
				@rm -f $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY:			all show re clean fclean test
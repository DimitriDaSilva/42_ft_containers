# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 09:33:15 by dda-silv          #+#    #+#              #
#    Updated: 2021/08/05 17:46:12 by dda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program built
FT_NAME				:=		ft_containers
STL_NAME			:=		stl_containers

# Name directory
PATH_SRC			:=		src
PATH_BUILD			:=		build
PATH_TESTING		:=		testing

# List of sources
SRCS				:=		$(shell find $(PATH_SRC) -name *.cpp)
OBJS				:=		$(SRCS:%.cpp=$(PATH_BUILD)/%.o)
DEPS				:=		$(OBJS:.o=.d)
INC_DIRS			:=		$(shell find $(PATH_SRC) -type d)

# Compiler
CC					:=		clang++

# Flags - compilation
FLAG_WARNING		:=		-Wall -Wextra -Werror -std=c++98
FLAG_INC			:= 		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE		:=		-MMD -MP
FLAG_DEBUG			:= 		-g
FLAG_OPTIMIZATION	:=		-O3
FLAGS_COMP			:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG) #$(FLAG_OPTIMIZATION)

# Flags - memory leak check
FLAG_MEM_LEAK		:= 		-fsanitize=address

# Others commands
RM					:=		rm -rf

# Color Code and template code
_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RESET				:=		\e[0m
_INFO				:=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS			:=		[$(_GREEN)SUCCESS$(_RESET)]
SEED				:=		$(shell echo $$RANDOM)
IS_FILE_EMPTY		:=

# General functions
all:						init $(FT_NAME) $(STL_NAME)
							@ printf "$(_SUCCESS) Compilation done\n"

init:
							@ printf "$(_INFO) Initialize $(FT_NAME)\n"
							@ printf "$(_INFO) Initialize $(STL_NAME)\n"

$(FT_NAME):					$(OBJS)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS) $(FLAG_LIBFT) -D IS_TEST=0

$(STL_NAME):				$(OBJS)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS) $(FLAG_LIBFT) -D IS_TEST=1

$(PATH_BUILD)/%.o:			%.cpp
							@ mkdir -p $(dir $@)
							@ $(CC) $(FLAGS_COMP) -c $< -o $@

bonus:						all

clean:
							@ $(RM) $(PATH_BUILD)
							@ $(RM) $(PATH_TESTING)
							@ printf "$(_INFO) Deleted files and directories\n"

fclean:						clean
							@ $(RM) $(FT_NAME) $(STL_NAME)
							@ printf "$(_INFO) Deleted binaries\n"

re:							fclean all

test:						debug
							@ mkdir -p $(PATH_TESTING)
							@ ./$(FT_NAME) $(SEED) > $(PATH_TESTING)/$(FT_NAME).log
							@ ./$(STL_NAME) $(SEED) > $(PATH_TESTING)/$(STL_NAME).log
							@ diff $(PATH_TESTING)/$(FT_NAME).log $(PATH_TESTING)/$(STL_NAME).log > ./$(PATH_TESTING)/diff.log
							@ ./test.sh
							@ cat $(PATH_TESTING)/diff.log


# Debugging functions

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						re

.PHONY:						all clean fclean re

-include $(DEPS)

# Source for some pieces of this Makefile: 
# https://makefiletutorial.com/#makefile-cookbook

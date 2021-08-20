# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 09:33:15 by dda-silv          #+#    #+#              #
#    Updated: 2021/08/20 12:30:34 by dda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program built
NAME_FT				:=		ft_containers
NAME_STL			:=		stl_containers

# Name directory
PATH_SRC			:=		tester
PATH_BUILD			:=		build
PATH_BUILD_FT		:=		$(PATH_BUILD)/ft
PATH_BUILD_STL		:=		$(PATH_BUILD)/stl
PATH_CONTAINERS		:=		containers
PATH_LOGS			:=		logs

# List of sources
SRCS				:=		$(shell find $(PATH_SRC) -name *.cpp)
OBJS_FT				:=		$(SRCS:%.cpp=$(PATH_BUILD_FT)/%.o)
OBJS_STL			:=		$(SRCS:%.cpp=$(PATH_BUILD_STL)/%.o)
DEPS_FT				:=		$(OBJS_FT:.o=.d)
DEPS_STL			:=		$(OBJS_STL:.o=.d)
INC_DIRS_SRC		:=		$(shell find $(PATH_SRC) -type d)
INC_DIRS_CONTAINERS	:=		$(shell find $(PATH_CONTAINERS) -type d)

# Compiler
CC					:=		clang++

# Flags - compilation
FLAG_WARNING		:=		-Wall -Wextra -Werror
FLAG_INC_SRC		:= 		$(addprefix -I, $(INC_DIRS_SRC))
FLAG_INC_CONTAINERS	:= 		$(addprefix -I, $(INC_DIRS_CONTAINERS))
FLAG_MAKEFILE		:=		-MMD -MP
FLAG_DEBUG			:= 		-g
FLAGS_COMP_FT		:= 		$(FLAG_WARNING) $(FLAG_MAKEFILE) $(FLAG_DEBUG) -std=c++98 $(FLAG_INC_SRC) $(FLAG_INC_CONTAINERS)
FLAGS_COMP_STL		:= 		$(FLAG_WARNING) $(FLAG_MAKEFILE) $(FLAG_DEBUG) -std=c++20 $(FLAG_INC_SRC) -D IS_TEST=1

# Flags - memory leak check
FLAG_MEM_LEAK		:= 		-fsanitize=address

# Others commands
RM					:=		rm -rf
SEED				:=		$(shell echo $$RANDOM)

# Color Code and template code
_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RED				:=		\e[38;5;9m
_RESET				:=		\e[0m
_INFO				:=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS			:=		[$(_GREEN)SUCCESS$(_RESET)]
_FAILURE			:=		[$(_RED)FAILURE$(_RESET)]

# General functions
all:						init $(NAME_FT) $(NAME_STL)
							@ printf "$(_SUCCESS) Compilation done\n"

init:
							@ printf "$(_INFO) Initialize $(NAME_FT)\n"
							@ printf "$(_INFO) Initialize $(NAME_STL)\n"

$(NAME_FT):					$(OBJS_FT)
							@ $(CC) $(FLAGS_COMP_FT) -o $@ $(OBJS_FT)

$(NAME_STL):				$(OBJS_STL)
							@ $(CC) $(FLAGS_COMP_STL) -o $@ $(OBJS_STL)

$(PATH_BUILD_FT)/%.o:		%.cpp
							@ mkdir -p $(dir $@)
							@ $(CC) $(FLAGS_COMP_FT) -c $< -o $@

$(PATH_BUILD_STL)/%.o:		%.cpp
							@ mkdir -p $(dir $@)
							@ $(CC) $(FLAGS_COMP_STL) -c $< -o $@

bonus:						all

clean:
							@ $(RM) $(PATH_BUILD)
							@ $(RM) $(PATH_LOGS)
							@ printf "$(_INFO) Deleted files and directories\n"

fclean:						clean
							@ $(RM) $(NAME_FT) $(NAME_STL)
							@ printf "$(_INFO) Deleted binaries\n"

re:							fclean all

test:						debug
							@ printf "$(_INFO) Starting test\n"
							@ mkdir -p $(PATH_LOGS)
							@ /usr/bin/time -o $(PATH_LOGS)/$(NAME_FT).time ./$(NAME_FT) $(SEED) > $(PATH_LOGS)/$(NAME_FT).log
							@ /usr/bin/time -o $(PATH_LOGS)/$(NAME_STL).time ./$(NAME_STL) $(SEED) > $(PATH_LOGS)/$(NAME_STL).log
							@ diff -I '^Capacity' $(PATH_LOGS)/$(NAME_FT).log $(PATH_LOGS)/$(NAME_STL).log > $(PATH_LOGS)/diff.log; [ $$? -ge 0 ]
							@ if [ -s $(PATH_LOGS)/diff.log ]; \
							then \
								printf "$(_FAILURE) Failed test. Check the logs:\n"; \
								cat $(PATH_LOGS)/diff.log; \
							else \
								printf "$(_SUCCESS) Test successful\n"; \
							fi;
							@ printf "$(_INFO) Time efficiency:\n"
							@ printf "ft_containers:  "
							@ cat $(PATH_LOGS)/$(NAME_FT).time | grep 'elapsed' | awk 'OFS=" " {print $$3}' | cut -d "e" -f 1
							@ printf "stl_containers: "
							@ cat $(PATH_LOGS)/$(NAME_STL).time | grep elapsed | awk 'OFS=" " {print $$3}' | cut -d "e" -f 1
							@ rm -f $(PATH_LOGS)/*.time $(PATH_LOGS)/log.diff

# Debugging functions

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						re

.PHONY:						all clean fclean re

-include $(DEPS)

# Source for some pieces of this Makefile:
# https://makefiletutorial.com/#makefile-cookbook

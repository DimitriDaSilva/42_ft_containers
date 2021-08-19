# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 09:33:15 by dda-silv          #+#    #+#              #
#    Updated: 2021/08/19 17:28:50 by dda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program built
FT_NAME				:=		ft_containers
STL_NAME			:=		stl_containers

# Name directory
PATH_SRC			:=		src
PATH_BUILD			:=		build
PATH_LOGS			:=		logs

# List of sources
SRCS				:=		$(shell find $(PATH_SRC) -name *.cpp)
OBJS				:=		$(SRCS:%.cpp=$(PATH_BUILD)/%.o)
DEPS				:=		$(OBJS:.o=.d)
INC_DIRS			:=		$(shell find $(PATH_SRC) -type d)

# Compiler
CC					:=		clang++

# Flags - compilation
FLAG_WARNING		:=		-Wall -Wextra -Werror
FLAG_CPP_VERSION	:=		-std=c++98
FLAG_INC			:= 		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE		:=		-MMD -MP
FLAG_DEBUG			:= 		-g
FLAG_OPTIMIZATION	:=		-O3
FLAGS_COMP			:= 		$(FLAG_WARNING) $(FLAG_CPP_VERSION) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG) #$(FLAG_OPTIMIZATION)

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
all:						init $(FT_NAME) $(STL_NAME)
							@ printf "$(_SUCCESS) Compilation done\n"

init:
							@ printf "$(_INFO) Initialize $(FT_NAME)\n"
							@ printf "$(_INFO) Initialize $(STL_NAME)\n"

$(FT_NAME):					$(OBJS)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS)

$(STL_NAME):				fclean
							@ $(CC) $(FLAG_WARNING) -g -std=c++20 -D IS_TEST=1 $(PATH_SRC)/main.cpp -o $@

$(PATH_BUILD)/%.o:			%.cpp
							@ mkdir -p $(dir $@)
							@ $(CC) $(FLAGS_COMP) -c $< -o $@

bonus:						all

clean:
							@ $(RM) $(PATH_BUILD)
							@ $(RM) $(PATH_LOGS)
							@ printf "$(_INFO) Deleted files and directories\n"

fclean:						clean
							@ $(RM) $(FT_NAME) $(STL_NAME)
							@ printf "$(_INFO) Deleted binaries\n"

re:							fclean all

test:						debug
							@ printf "$(_INFO) Starting test\n"
							@ mkdir -p $(PATH_LOGS)
							@ /usr/bin/time -o $(PATH_LOGS)/$(FT_NAME).time ./$(FT_NAME) $(SEED) > $(PATH_LOGS)/$(FT_NAME).log
							@ /usr/bin/time -o $(PATH_LOGS)/$(STL_NAME).time ./$(STL_NAME) $(SEED) > $(PATH_LOGS)/$(STL_NAME).log
							@ diff -I '^Capacity' $(PATH_LOGS)/$(FT_NAME).log $(PATH_LOGS)/$(STL_NAME).log > $(PATH_LOGS)/diff.log; [ $$? -ge 0 ]
							@ if [ -s $(PATH_LOGS)/diff.log ]; \
							then \
								printf "$(_FAILURE) Failed test. Check the logs:\n"; \
								cat $(PATH_LOGS)/diff.log; \
							else \
								printf "$(_SUCCESS) Test successful\n"; \
							fi; 
							@ printf "$(_INFO) Time efficiency:\n"
							@ printf "ft_containers:  "
							@ cat $(PATH_LOGS)/$(FT_NAME).time | grep 'elapsed' | awk 'OFS=" " {print $$3}' | cut -d "e" -f 1
							@ printf "stl_containers: "
							@ cat $(PATH_LOGS)/$(STL_NAME).time | grep elapsed | awk 'OFS=" " {print $$3}' | cut -d "e" -f 1
							@ rm -f $(PATH_LOGS)/*.time $(PATH_LOGS)/log.diff

# Debugging functions

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						re

.PHONY:						all clean fclean re

-include $(DEPS)

# Source for some pieces of this Makefile: 
# https://makefiletutorial.com/#makefile-cookbook

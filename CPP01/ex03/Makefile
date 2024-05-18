NAME		=  Unnecessary_violence
NPD			= --no-print-directory
OBJ_DIR		= obj/


# ----Libraryes----
INC_DIR = -I ./inc
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -O3 -g  -fsanitize=address
# =============

FILES = main HumanA HumanB Weapon

SRC = $(addsuffix .cpp, $(FILES))

vpath %.cpp src

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.cpp
	@$(MP) $(dir $@)
	@$(CC) $(CFLAGS) -MMD $(INC_DIR) -c $< -o $@
#echo "Object of the file $(basename $<) has been created 🤐"

all:
	@$(MAKE) $(NAME) $(NPD)

$(NAME):: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiling $(NAME) 😈"

$(NAME)::
	@echo "Hello, $(NAME) already compiled 🦆"

-include $(DEP)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(OBJ_DIR) has been removed 😭"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) has been destroyed 🥺🥺"

re:
	@$(MAKE) fclean $(NPD)
	@$(MAKE) $(NPD)

.PHONY: all clean fclean re
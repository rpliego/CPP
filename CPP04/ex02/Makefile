NAME		= Abstract
MKFL		= Makefile
NPD			= --no-print-directory
OBJ_DIR		= obj/


# ----Libraryes----
INC_DIR = inc/
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g -fsanitize=address
# =============

FILES = main Animal Dog Cat WrongAnimal WrongCat Brain

SRC = $(addsuffix .cpp, $(FILES))

vpath %.cpp src

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.cpp
	@$(MP) $(dir $@)
	@$(CC) $(CFLAGS) -MMD -I $(INC_DIR) -c $< -o $@
	@echo "Object of the file $(basename $<) has been created 🤐"

all:
	@$(MAKE) $(NAME) $(NPD)

$(NAME):: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiling $(NAME) 😈"

$(NAME)::
	@echo "Hello, $(NAME) already compiled 😇"

-include $(DEP)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean $(NPD)
	@$(MAKE) $(NPD)

.PHONY: all clean fclean re

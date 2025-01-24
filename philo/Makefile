.PHONY			:	clean fclean re all norme

NAME			=   philo

#			GCC

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror $(INCLUDE)
INCLUDE 		=	-I include

#			SRC

SRC_FILES		=	philo	\
					cleanup	\
					mutex	\
					print	\
					thread	\
					utils	\
					verif	\

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#			COMMON

OBJ_DIR			=	obj/
SRC_DIR			=	src/

#			RULES

all				:	$(NAME)

$(NAME)			:	$(OBJ_DIR) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -lpthread -o $(NAME)

$(OBJ_DIR)		:
				mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o	: 	$(SRC_DIR)%.c include/philo.h
				$(CC) $(CFLAGS) -c $< -o $@

norme			:
				norminette $(SRC_DIR) include

clean			:
				$(RM) -rf $(OBJ_DIR)

fclean			:	clean
				$(RM) -f $(NAME)

re				:	fclean all
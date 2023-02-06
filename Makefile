NAME				=	philo

OBJ_DIR				=	./obj
OBJS				=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADER_PATH			=	./includes
HEADER_FILES		=	defines.h philosophers.h

SRCS				=	$(PHILO)						

PHILO				=	main.c	utils.c check_input.c 	run_threads.c	\
						get_time.c routine.c init_philo.c actions.c		\
						destroy_philosophers.c

DIRS				=	. philosophers
IFLAGS				=	-I $(HEADER_PATH)
CFLAGS				=	-Wall -Wextra -Werror -pthread

VPATH				=	$(addprefix ./philosophers/, $(DIRS))
VPATH				+=	$(HEADER_PATH)

CFLAGS				+=	-g

WHITE				=	\e[00m
GREEN				=	\e[32m
RED					=	\e[91m
YELLOW				=	\e[033m
BLUE				=	\e[34m

NUMBER_OF_SRC_FILES	=	$(words $(SRCS))
PROGRESS			=	0

all: $(NAME)

$(NAME):  $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJS)
	@echo "$(GREEN)Philosophers compiled succesfully$(WHITE)"

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re:	fclean all

git:
	git add .
	git commit -m "$(m)"
	git push


val: all
	valgrind --leak-check=full --show-leak-kinds=all 


norm:
	@clear
	@norminette ${SRCS} ${INCDIR}* | grep Error || true

.PHONY:	all clean fclean re git test
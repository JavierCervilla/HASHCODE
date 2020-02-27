# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 03:12:16 by mpernia-          #+#    #+#              #
#    Updated: 2020/02/27 01:39:50 by mpernia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hashcode

INC_DIR		=	./includes/
LIBFT_DIR	=	$(INC_DIR)libft

CC			=	gcc
FLAGS		=	-c -Wall -Wextra -Werror

SRCS_DIR	=	./sources/
SRCS		=	$(addprefix $(SRCS_DIR), $(shell find $(SRCS_DIR)\
					-name "*.c" | rev | cut -d '/' -f1 | rev))

OBJS_DIR	=	./objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(shell find $(OBJS_DIR)\
					-name "*.o" | rev | cut -d '/' -f1 | rev))
OBJECTS		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -I$(SRCS_DIR) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "Adding libft..."
	@make -C $(LIBFT_DIR)
	@echo "Compiling objects..."
	$(CC) $(INC) main.c $(OBJS) -l ft -L $(LIBFT_DIR) -o $(NAME)
	./hashcode ./files/a_example.txt
	@echo "Done."

.PHONY: all clean fclean

debug:
	$(CC) $(INC) main.c $(SRCS) -l ft -L $(LIBFT_DIR) -g -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@echo "Cleaning hashcode objects..."
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "Cleaning hashcode..."

re: fclean all

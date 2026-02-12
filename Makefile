# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 14:40:42 by toandrad          #+#    #+#              #
#    Updated: 2026/02/12 14:53:19 by toandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

GREEN		= \033[0;32m
YELLOW		= \033[1;33m
BLUE		= \033[0;34m
RED			= \033[0;31m
BOLD		= \033[1m
RESET		= \033[0m

SRCDIR = src
OBJSDIR = objects
INCDIR = inc
VPATH = $(SRCDIR)

SRCS =	main.c parser.c utils.c init.c routine.c \
				routine_helpers.c monitor.c

OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

# ================================== RULES ================================== #

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)🛠️  Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -I$(INCDIR) -o $(NAME)
	@echo "$(GREEN)✅ Executable created: $(BLUE)$(NAME)$(RESET)"

$(OBJSDIR)/%.o: %.c | $(OBJSDIR)
	@echo "$(YELLOW)🔨 Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

clean:
	@rm -rf $(OBJSDIR)
	@echo "$(RED)🧹 Object files deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  All generated files deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 14:54:27 by ajearuth          #+#    #+#              #
#    Updated: 2022/02/07 16:11:53 by ajearuth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

# Project sources and objs 

SRCS = main.c init_philo.c error_management.c init_forks.c get_time.c actions.c
SRCSD = srcs/
OBJSD = objs/
OBJS = $(addprefix $(OBJSD), $(SRCS:.c=.o))

#  Bonus sources and objs 

BONUS_NAME = philosopher_bonus
BONUS_SRCS = 
BONUSD = bonus/
BONUSOD = $(BONUSD)objsb/
OBJSBONUS = $(addprefix $(BONUSOD), $(BONUS_SRCS:.c=.o))

CC = clang -c -o
COMPIL = clang
FLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME):	$(OBJS)
	$(COMPIL) $(FLAGS) $(OBJS) -o $@
	@echo "\033[0;32m\n          _         "
	@echo "   ______/ \-.   _  "
	@echo ".-/     (    o\_//    *~o~o~* OK *~o~o~* "
	@echo " |  ___  \_/\---'   "
	@echo "  |_||  |_||        "
	@echo "\033[0;35m                     Bonne correction !"


$(OBJSD)%.o: $(SRCSD)%.c
	mkdir -p $(OBJSD)
	$(CC) $@ $(FLAGS) $<

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(OBJSBONUS) 
	$(COMPIL) $(OBJSBONUS) -o $@

$(BONUSOD)%.o: $(BONUSD)%.c
	mkdir -p $(BONUSOD)
	$(CC) $@ $(FLAGS) $< 

clean:
	rm -rf $(OBJSD) $(BONUSOD)

fclean:	clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all 

.PHONY: all bonus clean fclean re

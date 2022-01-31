# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 14:54:27 by ajearuth          #+#    #+#              #
#    Updated: 2022/01/31 17:07:01 by ajearuth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

# Project sources and objs 

SRCS = main.c init_philo.c philosopher.h
SRCSD = srcs/
OBJSD = objs/
OBJS = $(addprefix $(OBJSD), $(SRCS:.c=.o))

#  Bonus sources and objs 

BONUS_NAME = philosopher_bonus
BONUS_SRCS = 
BONUSD = bonus/
BONUSOD = $(BONUSD)objsb/
OBJSBONUS = $(addprefix $(BONUSOD), $(BONUS_SRCS:.c=.o))

#DEPS = $(addprefix $(OBJD), $(SRCS:.c=.d))
CC = clang -c -o
COMPIL = clang
FLAGS = -Wall -Wextra -Werror

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
	$(CC) $@ $(FLAGS) -MMD $<

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(OBJSBONUS) 
	$(COMPIL) $(OBJSBONUS) -o $@

$(BONUSOD)%.o: $(BONUSD)%.c
	mkdir -p $(BONUSOD)
	$(CC) $@ $(FLAGS) -MMD $< 

clean:
	rm -rf $(OBJSD) $(BONUSOD)

fclean:	clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all 

#-include $(DEPS) 

.PHONY: all bonus clean fclean re

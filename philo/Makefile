# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 14:54:27 by ajearuth          #+#    #+#              #
#    Updated: 2022/01/31 14:09:34 by ajearuth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

# Project sources and objs 

SRCS = 
SRCSD = srcs/
OBJSD = objs/
OBJS = $(addprefix $(OBJSD), $(SRCS:.c=.o))

#  Bonus sources and objs 

BONUS_NAME = philosopher_bonus
BONUS_SRCS = 
BONUSD = bonus/
BONUSOD = $(BONUSD)objsb/
OBJSBONUS = $(addprefix $(BONUSOD), $(BONUS_SRCS:.c=.o))

# Libft sources and objs 

LIBSD = libs/
LIBFTD = $(addprefix $(LIBSD), libft/)
LIBFT = $(addprefix $(LIBFTD), libft.a)

#DEPS = $(addprefix $(OBJD), $(SRCS:.c=.d))
LIBS = $(LIBFT) $(MLX)
LIBS_MAKE = make -C
CC = clang -c -o
COMPIL = clang
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(LIBS) $(OBJS)
	$(COMPIL) $(FLAGS) $(OBJS) $(MLX_FLAGS) $(LIBS) -o $@
	@echo "\033[0;32m\n          _         "
	@echo "   ______/ \-.   _  "
	@echo ".-/     (    o\_//    *~o~o~* OK *~o~o~* "
	@echo " |  ___  \_/\---'   "
	@echo "  |_||  |_||        "
	@echo "\033[0;35m                     Bonne correction !"


$(OBJSD)%.o: $(SRCSD)%.c
	mkdir -p $(OBJSD)
	$(CC) $@ $(FLAGS) -I $(LIBFTD) -I $(MLXD) -MMD $<

$(LIBS):
	$(LIBS_MAKE) $(MLXD) all
	$(LIBS_MAKE) $(LIBFTD) bonus

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(LIBS) $(OBJSBONUS) 
	$(COMPIL) $(OBJSBONUS) $(MLX_FLAGS) $(LIBS) -o $@

$(BONUSOD)%.o: $(BONUSD)%.c
	mkdir -p $(BONUSOD)
	$(CC) $@ $(FLAGS) -I $(LIBFTD) -I $(MLXD) -MMD $< 

clean:
	rm -rf $(OBJSD) $(BONUSOD)
	$(LIBS_MAKE) $(LIBFTD) clean
	$(LIBS_MAKE) $(MLXD) clean

fclean:	clean
	rm -rf $(NAME) $(BONUS_NAME)
	$(LIBS_MAKE) $(LIBFTD) fclean
	$(LIBS_MAKE) $(MLXD) clean

re: fclean all 

#-include $(DEPS) 

.PHONY: all bonus clean fclean re


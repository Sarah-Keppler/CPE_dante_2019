##
## EPITECH PROJECT, 2019
## Dante's Star
## File description:
## Makefile from Lucas Marsala from Kevin Spegt
##
## --------------------------------------------------------------- ##
NAME	=	see below

## --------------------------------------------------------------- ##
REDDARK	=	\033[31;1m
REDDARK =       \033[31;1m
RED     =       \033[31;1m
GREEN   =       \033[32;1m
YEL     =       \033[33;1m
BLUE    =       \033[34;1m
PINK    =       \033[35;1m
CYAN    =       \033[36;1m
WHITE   =       \033[0m

## --------------------------------------------------------------- ##
CFLAGS	+=	-g		\
		-W		\
		-Wall		\
		-Wextra		\
		-Werror		\
		-pedantic	\
		-I./include/

## --------------------------------------------------------------- ##
all:	$(NAME)
	@printf	"$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)$(NAME)$(GREEN)] -> "
	@printf "$(WHITE)Compilation terminée."
	@printf "$ Binaire : $(CYAN) ./%s$(WHITE)\n\n" $(NAME)

$(NAME):
	make -C ./generator/
	make -C ./solver/

## --------------------------------------------------------------- ##
clean:
	rm -f generator/*.o
	rm -f solver/sources/*.o
	@printf "$(GREEN)\n$(WHITE)"
	@printf "$(GREEN)  [$(WHITE)$(NAME)$(GREEN)] -> "
	@printf "$(WHITE)Suppression terminée.\n\n"

pizza:
	rm -f *~
	rm -f ./generator/generator
	rm -f ./solver/solver
	rm -f vgcore.*


fclean:	pizza clean
	rm -f ./generator/generator
	rm -f ./solver/solver
	rm -f $(NAME)

re:	fclean all

.PHONY: re clean fclean all pizza

## ========================================================================= ##
%.o:    %.c
	@printf "$(GREEN)[$(WHITE)$(NAME)$(GREEN)] — $(WHITE)%-45s\n" $<
	@printf "$(GREEN) → $(RES) %-50s" $@
	@printf "$(GREEN)[$(WHITE)√$(GREEN)]\n\n"
	@gcc $(CFLAGS) -o $@ -c $<

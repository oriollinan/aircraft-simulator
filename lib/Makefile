##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## building and cleaning a library
##

ARR = my_arr/

LL = my_linkedlist/

NUM = my_num/

PRTF = my_printf/

STR = my_string/

GREEN = \n\e[1m\033

RESET = \033[0m\n

all:
	@echo "$(GREEN)[92mBuilding $(ARR)$(RESET)"
	make -C $(ARR)
	# @echo "$(GREEN)[92mBuilding $(LL)$(RESET)"
	# make -C $(LL)
	@echo "$(GREEN)[92mBuilding $(NUM)$(RESET)"
	make -C $(NUM)
	# @echo "$(GREEN)[92mBuilding $(PRTF)$(RESET)"
	# make -C $(PRTF)
	@echo "$(GREEN)[92mBuilding $(STR)$(RESET)"
	make -C $(STR)

clean:
	make clean -C $(ARR)
	# make clean -C $(LL)
	make clean -C $(NUM)
	# make clean -C $(PRTF)
	make clean -C $(STR)

fclean:
	make fclean -C $(ARR)
	# make fclean -C $(LL)
	make fclean -C $(NUM)
	# make fclean -C $(PRTF)
	make fclean -C $(STR)

re:	fclean all

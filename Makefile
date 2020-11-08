all : rxnbalancer

rxnbalancer : rxnbalancer.c
	gcc -Wall -Werror -o rxnbalancer rxnbalancer.c

clean :
	rm rxnbalancer
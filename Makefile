all : rxnbalancer

rxnbalancer : rxnbalancer.c node.c
	gcc -Wall -Werror -o rxnbalancer rxnbalancer.c node.c

clean :
	rm rxnbalancer
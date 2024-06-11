FLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE

all: s21_grep test
s21_grep:
	gcc $(FLAGS)  -o s21_grep s21_grep.c

style: 
	clang-format -style=Google -n ./*.c	-Werror

test: s21_grep
	chmod +x grep_test.sh
	./grep_test.sh
clean: 
	rm -rf *.o *.a *.out s21_grep *.py *.cfg

rebuild: clean all
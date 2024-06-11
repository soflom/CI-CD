FLAGS = -Wall -Wextra -Werror -std=c11
all: s21_cat test
s21_cat:
	gcc $(FLAGS) -o s21_cat s21_cat.c 

style: 
	clang-format -style=Google -n ./*.c	-Werror
	
test: s21_cat
	chmod +x test_cat.sh
	./test_cat.sh
clean:
	rm -rf *.o *.a *.out s21_cat *.cfg *.gcda *.py

rebuild: clean all
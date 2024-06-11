#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
  int b;  // Нумеровать строки, как и при указании опции -n, но пустые строки не
          // нумеруются.
  int e;  // Выдавать в конце каждой строки символ $ (перед символом новой
          // строки).
  int E;  // Тоже самое, но без -v
  int v;  // Выдавать непечатные символы. Управляющие символы ASCII.
  int n;  // Выдовать порядковый номер строки каждой строки.
  int s;  // Не выдавать сообщений о не существующих файлах.
  int t;  // Выдавать символы табуляции как ^I, а символы прогона страницы - как
          // ^L.
  int T;  // Тоже самое, но без -v
} flags;

void s21_cat(const char* filename, flags opt);

#endif  // S21_CAT_H_
#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <regex.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN_TEMPLATE 200
#define MAX_LEN_STRING 2000

struct forms {
  int flag_e;  //Шаблон
  int flag_i;  //Игнорирует различия регистра.
  int flag_v;  //Инвертирует смысл поиска соответствий.
  int flag_c;  //Выводит только количество совпадающих строк.
  int flag_l;  //Выводит только совпадающие файлы.
  int flag_n;  //Предваряет каждую строку вывода номером строки из файла ввода.
  int flag_h;  //Выводит совпадающие строки, не предваряя их именами файлов.
  int flag_s;  //Подавляет сообщения об ошибках о несуществующих или нечитаемых
               //файлах.
  int flag_f;  //Получает регулярные выражения из файла.
  int flag_o;  //Печатает только совпадающие (непустые) части совпавшей строки.
  int error;
  int amount_files;
  char template[MAX_LEN_TEMPLATE];
};

void init(struct forms* p);
void Parserflag(int argc, char* argv[], struct forms* new);
int Parsfile(int argc, char* argv[], struct forms* new);
int filtertextfile(FILE* file, const char* namefile, struct forms* new);
void PrintResult(char* read_string, regex_t* regexpression,
                 int count_strokes_number, int how_many_find,
                 const char* namefile, struct forms* new);
int Print_flag_f(char* read_string, const char* namefile, struct forms* new);

#endif  //  SRC_GREP_S21_GREP_H_

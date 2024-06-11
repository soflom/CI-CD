#include "s21_grep.h"

void init(struct forms* p) {
  p->flag_e = 0;
  p->flag_i = 0;
  p->flag_v = 0;
  p->flag_c = 0;
  p->flag_l = 0;
  p->flag_n = 0;
  p->flag_h = 0;
  p->flag_s = 0;
  p->flag_f = 0;
  p->flag_o = 0;
  p->error = 0;
  p->amount_files = 0;
  memset(p->template, 0, MAX_LEN_TEMPLATE);  //  Обнуляем массив
}

// Парсим флаги
void Parserflag(int argc, char* argv[], struct forms* new) {
  int count_flags = 0;  //  count_patterns = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] != '-') {
      count_flags++;
      int len_argv_i = strlen(argv[i]);
      for (int i_sub = 1; i_sub < len_argv_i; i_sub++) {
        if (argv[i][i_sub] == 'e') {
          new->flag_e = 1;
        } else if (argv[i][i_sub] == 'i') {
          new->flag_i = 1;
        } else if (argv[i][i_sub] == 'v') {
          new->flag_v = 1;
        } else if (argv[i][i_sub] == 'c') {
          new->flag_c = 1;
        } else if (argv[i][i_sub] == 'l') {
          new->flag_l = 1;
        } else if (argv[i][i_sub] == 'n') {
          new->flag_n = 1;
        } else if (argv[i][i_sub] == 'h') {
          new->flag_h = 1;
        } else if (argv[i][i_sub] == 's') {
          new->flag_s = 1;
        } else if (argv[i][i_sub] == 'f') {
          new->flag_f = 1;
        } else if (argv[i][i_sub] == 'o') {
          new->flag_o = 1;
        } else {
          new->error = 1;
        }
        snprintf(new->template, sizeof(new->template), "%s", argv[i + 1]);
      }
    } else if (argv[i][0] == '-' && argv[i][1] == '-') {
      count_flags++;
      if (strcmp(argv[i], "--regexp=patterns") == 0) {
        new->flag_e = 1;
      } else if (strcmp(argv[i], "--ignore-case") == 0) {
        new->flag_i = 1;
      } else if (strcmp(argv[i], "--invert-match") == 0) {
        new->flag_v = 1;
      } else if (strcmp(argv[i], "--count") == 0) {
        new->flag_c = 1;
      } else if (strcmp(argv[i], "--file-with_match") == 0) {
        new->flag_l = 1;
      } else if (strcmp(argv[i], "--line-number") == 0) {
        new->flag_n = 1;
      } else if (strcmp(argv[i], "--no-filename") == 0) {
        new->flag_h = 1;
      } else if (strcmp(argv[i], "--no-massage") == 0) {
        new->flag_s = 1;
      } else if (strcmp(argv[i], "--file") == 0) {
        new->flag_f = 1;
      } else if (strcmp(argv[i], "--only-matching") == 0) {
        new->flag_o = 1;
      } else {
        new->error = 1;
      }
      snprintf(new->template, sizeof(new->template), "%s", argv[i + 1]);
    }
  }
  if (count_flags == 0) {
    snprintf(new->template, sizeof(new->template), "%s", argv[1]);
  }
  new->amount_files = argc - 1 - 1 - count_flags;
}

/*
Парсим файл и открываем его
*/
int Parsfile(int argc, char* argv[], struct forms* new) {
  int flag = 0;
  const char* namefile = NULL;
  FILE* file = NULL;
  if (new->error != 1) {
    for (int length = argc - new->amount_files; length < argc; length++) {
      if ((file = fopen(argv[length], "rt")) != NULL) {
        namefile = argv[length];
        if (filtertextfile(file, namefile, new) == 1) {
          break;
        }
        fclose(file);
      } else if (!new->flag_s) {
        fprintf(stderr, "s21_grep %s: No such file or directory\n",
                argv[length]);
        flag = 1;
        break;
      }
    }
  } else if (!new->flag_s) {
    fprintf(stderr, "grep: invalid option\n");
    flag = 1;
  }
  return flag;
}

/*
Фильтруем текстовый файл, ищем совпадения по строкам
*/
int filtertextfile(FILE* file, const char* namefile, struct forms* new) {
  int flag = 0;
  int reg_ignore_case = 0;  //  2 - True (игнорируем ошибки)
  char read_string[MAX_LEN_STRING] = "";
  int count_strokes_number = 0;
  int how_many_find = 0;
  regex_t regexpression;
  if (new->flag_i) {
    reg_ignore_case = REG_ICASE;  //  REG_ICASE - игнорируем регистр
  }
  regcomp(&regexpression, new->template, reg_ignore_case);
  while (fgets(read_string, sizeof(read_string), file)) {
    count_strokes_number++;
    int result_find_reg = regexec(&regexpression, read_string, 0, NULL, 0);
    if (((!result_find_reg && !new->flag_l) ||
         (result_find_reg == REG_NOMATCH && new->flag_v)) &&
        !new->flag_f) {
      how_many_find++;
      PrintResult(read_string, &regexpression, count_strokes_number,
                  how_many_find, namefile, new);
    } else if (new->flag_f) {
      if (Print_flag_f(read_string, namefile, new) == 1) {
        flag = 1;
        break;
      }
    } else if (new->flag_l) {
      if (!result_find_reg) {
        printf("%s\n", namefile);
      }
      break;
    }
  }
  if (new->flag_c) {
    if (new->amount_files > 1 && !new->flag_h) {
      printf("%s:%d\n", namefile, how_many_find);
    } else {
      printf("%d\n", how_many_find);
    }
  }
  regfree(&regexpression);
  return flag;
}

/*
Печатаем результат
*/
void PrintResult(char* read_string, regex_t* regexpression,
                 int count_strokes_number, int how_many_find,
                 const char* namefile, struct forms* new) {
  int result_find_reg = 0;
  result_find_reg = regexec(regexpression, read_string, 0, NULL, 0);
  if (!new->flag_c && !new->flag_f && !new->flag_l) {
    if (new->flag_v) {
      if (result_find_reg == REG_NOMATCH) {
        if (new->amount_files > 1 && !new->flag_h) {
          printf("%s:%s", namefile, read_string);
        } else {
          printf("%s", read_string);
        }
      }
    } else if (new->flag_n) {
      if (new->amount_files > 1 && !new->flag_h) {
        printf("%s:%d:%s", namefile, count_strokes_number, read_string);
      } else {
        printf("%d:%s", count_strokes_number, read_string);
      }
    } else if (new->flag_o) {
      size_t nmatch = 2;
      regmatch_t temp[2];
      regoff_t length;
      result_find_reg = regexec(regexpression, read_string, nmatch, temp, 0);
      char* ptr = read_string;
      while (result_find_reg != REG_NOMATCH) {
        if (ptr == read_string) {
          how_many_find++;
        }
        length = temp[0].rm_eo - temp[0].rm_so;
        int length_int = length;
        if (new->amount_files > 1 && !new->flag_h && ptr == read_string) {
          printf("%s:%.*s\n", namefile, length_int, ptr + temp[0].rm_so);
        } else {
          printf("%.*s\n", length_int, ptr + temp[0].rm_so);
        }
        ptr += temp[0].rm_eo;
        result_find_reg =
            regexec(regexpression, ptr, nmatch, temp, 0);  // ищем совпадения
      }
    } else {
      if (new->amount_files > 1 && !new->flag_h) {
        printf("%s:%s", namefile, read_string);
      } else {
        printf("%s", read_string);
      }
    }
    int last_symbol_in_stroke = strlen(read_string);
    if (((!result_find_reg && !new->flag_v) ||
         (result_find_reg == REG_NOMATCH && new->flag_v)) &&
        read_string[last_symbol_in_stroke - 1] != '\n') {
      printf("\n");
    }
  }
}

int Print_flag_f(char* read_string, const char* namefile, struct forms* new) {
  FILE* file_template = NULL;
  int flag = 0;
  regex_t regexpr_from_file;

  if ((file_template = fopen(new->template, "rt")) != NULL) {
    char read_template[MAX_LEN_STRING] = "";
    while (fgets(read_template, sizeof(read_template), file_template)) {
      int length_of_template = strlen(read_template);
      if (read_template[length_of_template - 1] == '\n') {
        read_template[length_of_template] = '\0';
      }
      regcomp(&regexpr_from_file, read_template,
              0);  // обрабатываем регулярные выражения для флага ф
      int result_find_reg = regexec(&regexpr_from_file, read_string, 0, NULL,
                                    0);  // через regexec ищем совпадения
      if (!result_find_reg) {
        if (new->flag_c) {
          if (new->amount_files > 1 && !new->flag_h) {
            printf("%s:%s", namefile, read_string);
          } else {
            printf("%s", read_string);
          }
        }
        int last_symbole_in_line = strlen(read_string);
        if (read_string[last_symbole_in_line - 1] != '\n') {
          printf("\n");
        }
        break;
      }
      regfree(&regexpr_from_file);  // очищаем память для регулярного выражения
    }
    fclose(file_template);
  } else if (!new->flag_s) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", new->template);
    flag = 1;
  }
  return flag;
}

/*
Главная функция
*/

int main(int argc, char* argv[]) {
  struct forms new;
  init(&new);
  int flag = 0;
  if (argc > 1) {
    Parserflag(argc, argv, &new);
    if (Parsfile(argc, argv, &new) == 1) {
      flag = 1;
    }
  } else {
    flag = 1;
  }
  return flag;
}

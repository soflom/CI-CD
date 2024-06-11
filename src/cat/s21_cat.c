#include "s21_cat.h"

int main(int argc, char *argv[]) {
  // int option_val = 0;
  int opindex = 0;
  int opchar = 0;
  // char filename[256] = {'\0'};

  struct option opts[] = {
      {"number", no_argument, 0, 'n'},
      {"squeeze-blank", no_argument, 0, 's'},
      {"number-nonblank", no_argument, 0, 'b'},
      {0, 0, 0, 0},
  };
  flags opt = {0};

  while (-1 != (opchar = getopt_long(argc, argv, "nesbtvET", opts, &opindex))) {
    switch (opchar) {
      case 'n':
        opt.n = TRUE;
        // printf("opt.n true \n");
        // flag_n("test.txt");
        break;
      case 'e':
        opt.e = TRUE;
        opt.v = TRUE;
        // printf("opt.e true \n");
        // flag_e("test.txt");
        break;
      case 's':
        opt.s = TRUE;
        // printf("opt.s true \n");
        // flag_s("test.txt");
        break;
      case 'b':
        opt.b = TRUE;
        // printf("opt.b true \n");
        // flag_b("test.txt");
        break;
      case 't':
        opt.t = TRUE;
        opt.v = TRUE;
        // printf("opt.t true \n");
        // flag_t("test.txt");
        break;
      case 'v':
        opt.v = TRUE;
        break;
      case 'T':
        opt.t = TRUE;
        break;
      case 'E':
        opt.e = TRUE;
        break;
      default:
        // printf("proebal");
        break;
    }
  }

  for (int j = optind; j < argc; j++) {  // передаем название файла в функцию
    s21_cat(argv[j], opt);
  }
}

void s21_cat(const char *filename, flags opt) {
  char ch;  // ch-текущий символ ch1-предыдущий символ
  char ch1 = '\n';
  int count = 1;
  int empty_str = 0;
  FILE *file = fopen(filename, "r");
  while (!feof(file) && !ferror(file)) {
    ch = getc(file);
    if (ch != EOF) {
      if (opt.n) {
        if (ch1 == '\n') {
          printf("%6d\t", count++);
        }
        printf("%c", ch);
      } else if (opt.e || opt.E) {
        if (((ch >= 0 && ch < 9) || (ch > 10 && ch < 32) || (ch > 126)) &&
            (opt.v)) {
          printf("^");
          if (ch > 126) {
            ch -= 64;
          } else {
            ch += 64;
          }
        }
        if (ch == '\n') {
          printf("$");
        }
        printf("%c", ch);
      } else if (opt.b) {
        if ((ch != '\n') && (ch1 == '\n')) {
          printf("%6d\t", count++);
        }
        printf("%c", ch);
      } else if (opt.t || opt.T) {
        if (((ch >= 0 && ch < 9) || (ch > 10 && ch < 32) || (ch > 126)) &&
            (opt.v)) {
          printf("^");
          if (ch > 126) {
            ch -= 64;
          } else {
            ch += 64;
          }
        }
        if (ch == '\t') {
          printf("^I");
        } else {
          printf("%c", ch);
        }
      } else if (opt.s) {
        if ((ch1 == '\n') && (ch == '\n')) {
          empty_str++;
          if (empty_str > 1) {
            continue;
          }
        } else {
          empty_str = 0;
        }
        printf("%c", ch);
      } else if (opt.v) {
        if ((ch >= 0 && ch < 9) || (ch > 10 && ch < 32) || (ch > 126)) {
          printf("^");
          if (ch > 126) {
            ch -= 64;
          } else {
            ch += 64;
          }
        }
        printf("%c", ch);
      } else {
        printf("%c", ch);
      }
      ch1 = ch;
    }
  }
  fclose(file);
}

#include "study_grep.h"

int main(int argc, char **argv) {
  get_flags_and_options(argc, argv);
  return 0;
}

void get_flags_and_options(int argc, char **argv) {
  if (argc == 1) {
    printf("%s", hint);
    flags.wrong_flag++;
  } else {
    int rez;
    while ((rez = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
      switch (rez) {
        case 'e':
          flags.e++;
          flags.more_then_one++;
          if (flags.more_then_one > 1) {
            strcat(flags.for_e_flag_string, " ");
            strcat(flags.for_e_flag_string, optarg);
          }
          break;
        case 'i':
          flags.i = REG_ICASE;
          break;
        case 'v':
          flags.v++;
          break;
        case 'c':
          flags.c++;
          break;
        case 'l':
          flags.l++;
          break;
        case 'n':
          flags.n++;
          break;
        case 'h':
          flags.h++;
          break;
        case 's':
          flags.s++;
          break;
        case 'f':
          flags.f++;
          strcpy(flags.path_to_file, optarg);
          break;
        case 'o':
          flags.o++;
          break;
        case '?':
          printf("%s", hint);
          flags.wrong_flag = 1;
          break;
      }
    }
  }
  if (!flags.wrong_flag && argc >= 3) grep_it(argc, argv);
}

void grep_it(int argc, char **argv) {
  FILE *mf;
  char reg_pattern[REX_LINE_SIZE];
  char line[BUFLEN];
  char *temp = NULL;
  regex_t regex_str;
  int rc;
  int regflag = 0;
  size_t c_count = 0;
  size_t n_count = 0;
  short more_files = 0;

  if (flags.f) {
    FILE *fp;
    size_t i = 0;
    if ((fp = fopen(flags.path_to_file, "r")) == NULL && !flags.s) {
      perror("can't open the file:\t");
      ferror(fp);
    } else {
      for (; 1; i++) {
        char c = fgetc(fp);
        if (feof(fp)) break;
        if (c != '\n') {
          reg_pattern[i] = c;
        } else {
          reg_pattern[i] = '|';
        }
      }

      if (reg_pattern[i - 1] == '|') {
        reg_pattern[i - 1] = '\0';
      } else {
        reg_pattern[i] = '\0';
      }
      optind--;
    }
  } else if (flags.e && flags.more_then_one > 1) {
    strcpy(reg_pattern, flags.for_e_flag_string);
    regflag = REG_EXTENDED;
    optind--;
  } else if (flags.e && flags.more_then_one == 1) {
    strcpy(reg_pattern, argv[--optind]);
    regflag = REG_EXTENDED;
  } else {
    strcpy(reg_pattern, argv[optind]);
  }

  if (flags.i) {
    regflag = flags.i;
  }

  while (++optind < argc) {
    strcpy(flags.f_name, argv[optind]);
    n_count = 0;
    c_count = 0;
    if (!flags.h) {
      if ((argc - optind) > 1) {
        more_files = 1;
      }
    }

    if ((mf = fopen(flags.f_name, "r")) == NULL && !flags.s) {
      perror("can't open the file: \t");
      ferror(mf);
    } else {
      if ((regcomp(&regex_str, reg_pattern, regflag)) == 0) {
        while (fgets(line, BUFLEN, mf)) {
          n_count++;
          int limit = strlen(line);
          if ((line[limit - 1]) != '\n') {
            line[limit] = '\n';
            line[++limit] = '\0';
          }
          rc = regexec(&regex_str, line, 0, 0, 0);
          if (flags.v) {
            rc = !rc;
          }
          if (rc == 0) {
            if (flags.c || flags.l) {
              c_count++;
            } else if (flags.o) {
              temp = line;
              while ((temp = strstr(temp, reg_pattern))) {
                if (flags.n) {
                  if (more_files) {
                    P("%s:%lu:%s\n", flags.f_name, n_count, reg_pattern);
                  } else {
                    P("%lu:%s\n", n_count, reg_pattern);
                  }
                } else {
                  P("%s\n", reg_pattern);
                }
                temp++;
              }
            } else {
              if (flags.n) {
                if (more_files) {
                  P("%s:%lu:%s", flags.f_name, n_count, line);
                } else {
                  P("%lu:%s", n_count, line);
                }
              } else {
                if (more_files) {
                  P("%s:%s", flags.f_name, line);
                } else {
                  P("%s", line);
                }
              }
            }
          }
        }
        if (flags.c || flags.l) {
          if (flags.c) {
            if (more_files) {
              P("%s:%lu\n", flags.f_name, c_count);
            } else {
              P("%lu\n", c_count);
            }
          }
          if (flags.l) {
            P("%s\n", flags.f_name);
          }
        }
        fclose(mf);
        regfree(&regex_str);
      }
    }
  }
}

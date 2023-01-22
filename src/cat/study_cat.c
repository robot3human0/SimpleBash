#include "study_cat.h"

int main(int argc, char *argv[]) {
  int rez = 0;
  int option_index;
  flags.only_one = 0;

  while ((rez = getopt_long(argc, argv, "benstETv", long_options,
                            &option_index)) != -1) {
    if (help_flag) {
      option_list();
    } else if (version_flag) {
      P("study_cat by Sidharta aka 'robot3human0'\tversion 1.0");
    } else {
      switch (rez) {
        case 'b':
          flags.b = 1;
          flags.only_one++;
          break;
        case 'e':
          flags.e_e = 1;
          flags.only_one++;
          break;
        case 'E':
          flags.e = 1;
          flags.only_one++;
          break;
        case 'n':
          flags.n = 1;
          flags.only_one++;
          break;
        case 's':
          flags.s = 1;
          flags.only_one++;
          break;
        case 't':
          flags.t_t = 1;
          flags.only_one++;
          break;
        case 'T':
          flags.t = 1;
          flags.only_one++;
          break;
        case 'v':
          flags.v = 1;
          flags.only_one++;
          break;
        default:
          P("%s\n", hint);
          flags.end = 1;
          break;
      }
    }
    // if (flags.end) break;
  }
  if (flags.only_one > 1) {
    flags.end = 1;
    P("%s\n", hint);
  } else {
    while (optind < argc && argc > 1 && !flags.end) {
      flags.count = 1;
      print_file(argv[optind++]);
    }
  }
  return 0;
}

void print_file(const char *file_name) {
  FILE *file;
  char line[LINE_LIMIT];
  char fline[LINE_LIMIT];
  int empty_line_count = 0;
  if ((file = fopen(file_name, "r")) == NULL) {
    P("Error: can't open the FILE!\n");
    return;
  }
  if (flags.e_e || flags.t_t || flags.v) {
    char c;
    while ((fscanf(file, "%c", &c)) != EOF) {
      print_char(c);
    }
  } else {
    while (fgets(line, LINE_LIMIT, file)) {
      if (flags.s) {
        if (line[0] == '\n') {
          empty_line_count++;
          if (empty_line_count > 1) {
            continue;
          }
        }
      }
      if (empty_line_count > 1 && line[0] != '\n') empty_line_count = 0;
      P("%s", apply_flags(line, fline));
    }
  }
  fclose(file);
}

char *apply_flags(char *line, char *fline) {
  char label = 0;

  if (flags.s) {
    strcpy(fline, line);
    label = 1;
  } else if (flags.n || flags.b) {
    if (label) strcpy(line, fline);
    if (flags.n) {
      snprintf(fline, LINE_LIMIT, "%6lu\t", flags.count++);
      strcat(fline, line);
    } else {
      if (strlen(line) > 1) {
        snprintf(fline, LINE_LIMIT, "%6lu\t", flags.count++);
        strcat(fline, line);
      } else {
        strcpy(fline, "\n");
      }
    }
    label = 1;
  } else if (flags.t) {
    if (label) strcpy(line, fline);
    size_t j = 0, i = 0;
    for (; line[j] != '\0'; i++, j++) {
      if (line[j] == '\t') {
        fline[i] = '^';
        fline[++i] = 'I';
        continue;
      }
      fline[i] = line[j];
    }
    fline[i] = '\0';
    label = 1;
  } else if (flags.e) {
    if (label) strcpy(line, fline);
    strcpy(fline, line);
    if ((fline[strlen(line) - 1]) == '\n') {
      fline[strlen(line) - 1] = '$';
      strcat(fline, "\n");
    }
    label = 1;
  } else {
    strcpy(fline, line);
  }

  return fline;
}

void print_char(char c) {
  if (flags.t_t) {
    if ((c >= 0 && c <= 8) || (c >= 11 && c <= 31)) {
      P("^%c", c + 64);
    } else if (c == 9) {
      P("^I");
    } else if (c == 127) {
      P("^%c", c - 64);
    } else {
      P("%c", c);
    }
  } else if (flags.e_e) {
    if ((c >= 0 && c <= 8) || (c >= 11 && c <= 31)) {
      P("^%c", c + 64);
    } else if (c == 10) {
      P("$\n");
    } else if (c == 127) {
      P("^%c", c - 64);
    } else {
      P("%c", c);
    }
  } else if (flags.v) {
    if ((c >= 0 && c <= 8) || (c >= 11 && c <= 31)) {
      P("^%c", c + 64);
    } else if (c == 127) {
      P("^%c", c - 64);
    } else {
      P("%c", c);
    }
  }
}

void option_list() {
  P("Usage: study_cat [OPTION]... [FILE]...\n");
  P("Concatinate FILE(s) to standart output.\n");
  P("\n");
  P("With no FILE, or when FILE is -, read standart input.\n");
  P("\n");
  P("-b, --number-nonblank \tnumber nonempty output lines, overrides -n\n");
  P("-e                    \tequivalent to -vE\n");
  P("-E, --show-ends       \tdisplay $ at end of each line\n");
  P("-n, --number          \tnumber all outputs lines\n");
  P("-s, --squeeze-blank   \tsuppress repeated empty output lines\n");
  P("-t                    \tequivalent to -vT\n");
  P("-T, --show-tabs       \tdisplay TAB characters as ^I\n");
  // P("-v, --show-nonprinting\tuse ^ and M- notation, expect for LFD and "
  //   "TAB\n");
  P("    --help            \tdisplay this help and exit.\n");
  P("    --version         \toutput version information and exit.\n");
  P("\n");
}

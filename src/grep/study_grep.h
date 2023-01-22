#ifndef SRC_GREP_STUDY_GREP_H_
#define SRC_GREP_STUDY_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P printf
#define REX_LINE_SIZE 1024
#define BUFLEN 4096

struct {
  int e, i, v, c, l, n, h, s, f, o;
  size_t more_then_one;
  int e_flag_count;
  int wrong_flag;
  char path_to_file[REX_LINE_SIZE];
  char f_name[REX_LINE_SIZE];
  char for_e_flag_string[REX_LINE_SIZE];
  int few_files;
} flags;

void get_flags_and_options(int argc, char **argv);
void grep_it(int argc, char **argv);

const char *hint = "usage: study_grep [-eivclnhso[f file]] [patern] [file ...]\n";
#endif  //  SRC_GREP_STUDY_GREP_H_

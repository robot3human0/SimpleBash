#ifndef SRC_CAT_STUDY_CAT_H_
#define SRC_CAT_STUDY_CAT_H_

#include <dirent.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>

#define P printf
#define LINE_LIMIT 1000

void print_file(const char* file_name);
char* apply_flags(char* line, char* fline);
void print_char(char c);

struct {
  char b, e, n, s, t, e_e, t_t, v;
  int end;
  size_t only_one;
  size_t count;
} flags;

#if __APPLE__
const int help_flag = 0;
const int version_flag = 0;
#define OPTIONS
const struct option long_options[] = {{NULL, 0, NULL, 0}};
const char hint[] = "usage: study_cat [-benst] [file ...]";
#elif __linux__
int help_flag = 0;
int version_flag = 0;
#define OPTIONS
const struct option long_options[] = {
    {"number-nonblank", no_argument, NULL, 'b'},
    {"show-ends", no_argument, NULL, 'E'},
    {"number", no_argument, NULL, 'n'},
    {"squeeze-blank", no_argument, NULL, 's'},
    {"show-tabs", no_argument, NULL, 'T'},
    {"show-nonprinting", no_argument, NULL, 'v'},
    {"help", no_argument, &help_flag, 1},
    {"version", no_argument, &version_flag, 1},
    {NULL, 0, NULL, 0}};
const char hint[] = "Try 'study_cat --help' for more information";
#endif
void option_list();

#endif  //  SRC_CAT_STUDY_CAT_H_

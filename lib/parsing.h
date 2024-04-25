#ifndef LABWORK3_KV1SIDISI__PARSING_H_
#define LABWORK3_KV1SIDISI__PARSING_H_

#include <iostream>
#include <cstring>
#include <fstream>

enum Options {
  input,
  output,
  max_iter,
  freq
};

struct Info {
  int16_t length;
  int16_t width;
  char* input;
  char* output;
  size_t max_iter;
  size_t freq;
  bool is_there_option[4];
};

void Parsing(int argc, char** argv, Info& arguments);

#endif //LABWORK3_KV1SIDISI__PARSING_H_
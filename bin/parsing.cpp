#include "../lib/parsing.h"

void Parsing(int argc, char** argv, Info& arguments) {
  for (bool& i : arguments.is_there_option) {
    i = false;
  }

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-i") == 0 or strcmp(argv[i], "--input") == 0) {
      i++;
      arguments.input = argv[i];
      arguments.is_there_option[input] = true;
    }
    else if (strcmp(argv[i], "-o") == 0 or strcmp(argv[i], "--output") == 0) {
      i++;
      arguments.output = argv[i];
      arguments.is_there_option[output] = true;
    }
    else if (strcmp(argv[i], "-m") == 0 or strcmp(argv[i], "--max-iter") == 0) {
      i++;
      arguments.max_iter = atoi(argv[i]);
      arguments.is_there_option[max_iter] = true;
    }
    else if (strcmp(argv[i], "-f") == 0 or strcmp(argv[i], "--freq") == 0) {
      i++;
      arguments.freq = atoi(argv[i]);
      arguments.is_there_option[freq] = true;
    }
    else {
      std::cerr << "error: Wrong option" << std::endl;
    }
  }

  for (bool i : arguments.is_there_option) {
    if (!i) {
      std::cerr << "error: Not all parameters were not entered" << std::endl;
      exit(-1);
    }
  }
}
#include <iostream>
#include "../lib/parsing.h"
#include "../lib/create_grid.h"
#include "../lib/create_bmp.h"

int main(int argc, char** argv) {
  Info arguments;
  Parsing(argc, argv, arguments);

  int cells_to_spill = 0;
  GridSize(arguments, cells_to_spill);

  int16_t** grid = new int16_t* [arguments.width];
  for (int x = 0; x < arguments.width; x++) {
    grid[x] = new int16_t[arguments.length];
  }

  InputReading(arguments, grid);

  int iterations_done = 0;
  if (cells_to_spill == 0) {
    CreateBmp(arguments, grid);
  }
  else {
    while (cells_to_spill != 0) {

      grid = Interation(arguments, cells_to_spill, grid);
      iterations_done++;

//      long long iter = 10000;
//      if (iterations_done == iter) {
//        iter += 10000;
//        std::cout << iterations_done << std::endl;
//      }

      if (arguments.max_iter == iterations_done) {
        break;
      }
      if (arguments.freq != 0) {
        if (iterations_done % arguments.freq == 0 && cells_to_spill != 0) {
          CreateBmp(arguments, grid);
        }
      }
    }

    if (arguments.freq == 0) {
      CreateBmp(arguments, grid);
    }
  }
}
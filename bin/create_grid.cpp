#include <set>
#include "../lib/create_grid.h"

void GridSize(Info& arguments, int& cells_to_spill) {
  std::ifstream fin(arguments.input);
  if (!fin.is_open()) {
    std::cout << "File open 1Error";
    exit(-1);
  }
  int16_t maxim_length = 0;
  int16_t minim_length = INT16_MAX;
  int16_t maxim_width = 0;
  int16_t minim_width = INT16_MAX;
  int16_t x;
  int16_t y;
  int16_t grain;

  while (fin.good()) {
    fin >> x;
    fin >> y;
    fin >> grain;
    if (grain >= 4) {
      cells_to_spill++;
    }
    if (x > maxim_width) {
      maxim_width = x;
    }
    if (x < minim_width) {
      minim_width = x;
    }
    if (y > maxim_length) {
      maxim_length = y;
    }
    if (y < minim_length) {
      minim_length = y;
    }
  }

  arguments.length = (maxim_length + minim_length + 3);
  arguments.width = (maxim_width + minim_width + 3);
}

void InputReading(Info& arguments, int16_t** grid) {
  std::ifstream fin(arguments.input);
  if (!fin.is_open()) {
    std::cout << "File open Error";
    exit(-1);
  }

  int16_t x;
  int16_t y;
  int16_t grains;

  for (int i = 0; i < arguments.width; i++) {
    for (int j = 0; j < arguments.length; ++j) {
      grid[i][j] = 0;
    }
  }

  while (fin.good()) {
    fin >> x;
    fin >> y;
    fin >> grains;
    grid[x + 1][y + 1] = grains;
  }
}

int16_t** UpdateGrid(Info& arguments, int16_t** grid, side key) {
  int width_increse = 0;
  int length_increse = 0;
  int move_down = 0;
  int move_right = 0;

  if (key == top) {
    width_increse++;
    move_down++;
  }
  if (key == bottom) {
    width_increse++;
  }
  if (key == right) {
    length_increse++;
  }
  if (key == left) {
    length_increse++;
    move_right++;
  }

  int16_t** grid_ptr = new int16_t* [arguments.width + width_increse];
  for (int i = 0; i < arguments.width + width_increse; i++) {
    grid_ptr[i] = new int16_t[arguments.length + length_increse];
  }

  for (int x = 0; x < arguments.width + width_increse; x++) {
    for (int y = 0; y < arguments.length + length_increse; y++) {
      grid_ptr[x][y] = 0;
    }
  }

  for (int x = 0; x < arguments.width; x++) {
    for (int y = 0; y < arguments.length; y++) {
      grid_ptr[x + move_down][y + move_right] = grid[x][y];
    }
  }

  for (int i = 0; i < arguments.width; i++) {
    delete[] grid[i];
  }
  delete[] grid;
  grid = grid_ptr;
  arguments.width += width_increse;
  arguments.length += length_increse;

  return grid;
}

int16_t** Interation(Info& arguments, int& cells_to_spill, int16_t** grid) {
  std::set<std::pair<uint16_t, uint16_t>> ignoring;
  std::pair<uint16_t, uint16_t> temporary;

  for (int x = 0; x < arguments.width; x++) {
    for (int y = 0; y < arguments.length; y++) {
      temporary = std::make_pair(x, y);
      if (ignoring.count(temporary) == 1) {
        continue;
      }
      if (grid[x][y] >= 4) {
        if (x == 0) {
          grid = UpdateGrid(arguments, grid, top);
          x++;
        }
        if (x + 1 == arguments.width) {
          grid = UpdateGrid(arguments, grid, bottom);
        }
        if (y == 0) {
          grid = UpdateGrid(arguments, grid, left);
          y++;
        }
        if (y + 1 == arguments.length) {
          grid = UpdateGrid(arguments, grid, right);
        }

        grid[x][y] -= 4;
        grid[x - 1][y]++;
        grid[x + 1][y]++;
        grid[x][y + 1]++;
        grid[x][y - 1]++;

        if (grid[x][y] < 4) {
          cells_to_spill--;
        }
        if (grid[x - 1][y] == 4) {
          temporary = std::make_pair(x - 1, y);
          ignoring.insert(temporary);
          cells_to_spill++;
        }
        if (grid[x + 1][y] == 4) {
          temporary = std::make_pair(x + 1, y);
          ignoring.insert(temporary);
          cells_to_spill++;
        }
        if (grid[x][y - 1] == 4) {
          temporary = std::make_pair(x, y - 1);
          ignoring.insert(temporary);
          cells_to_spill++;
        }
        if (grid[x][y + 1] == 4) {
          temporary = std::make_pair(x, y + 1);
          ignoring.insert(temporary);
          cells_to_spill++;
        }
      }
    }
  }

  return grid;
}



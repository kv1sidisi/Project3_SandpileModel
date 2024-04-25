#ifndef LABWORK3_KV1SIDISI__CREATE_GRID_H_
#define LABWORK3_KV1SIDISI__CREATE_GRID_H_

#include <iostream>
#include "parsing.h"
#include "fstream"

enum side {
  top = 0,
  right = 1,
  bottom = 2,
  left = 3
};

int16_t** UpdateGrid(Info& arguments, int16_t** grid, bool to_add[]);

void GridSize(Info& arguments, int& cells_to_spill);

void InputReading(Info& arguments, int16_t** grid);

int16_t** Interation(Info& arguments, int& cells_to_spill, int16_t** grid);

#endif //LABWORK3_KV1SIDISI__CREATE_GRID_H_

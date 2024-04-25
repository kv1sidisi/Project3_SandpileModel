#include <fstream>
#include <iostream>
#include <cstdint>
#include "parsing.h"
#ifndef LABWORK3_KV1SIDISI__CREATE_BMP_H_
#define LABWORK3_KV1SIDISI__CREATE_BMP_H_

void CreateBmp(const Info& arguments, int16_t** grid);

void ToNumbers4(int x, uint8_t numbers_4[]);

std::string GetPath(const char* path);

#endif //LABWORK3_KV1SIDISI__CREATE_BMP_H_

#ifndef FILE_UTILS_H_
#define FILE_UTILS_H_

#include <cstdint>
#include <fstream>
#include <vector>

std::vector<uint8_t> read_file(const char *file_name);

#endif

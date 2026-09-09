#include "file_utils.h"
#include <iostream>

std::vector<uint8_t> read_file(const char *file_name) {
  std::fstream bin_file;
  std::vector<uint8_t> buffer;
  uint32_t length = 0;

  if (file_name != nullptr) {
    bin_file.open(file_name, std::fstream::in | std::fstream::binary);
    bin_file.seekg(0, bin_file.end);
    length = bin_file.tellg();
    bin_file.seekg(0, bin_file.beg);

    if (length != 0) {
      buffer.resize(length);
      // trick read() to load our uint8_t, since it demands a char*
      bin_file.read(reinterpret_cast<char *>(buffer.data()), length);
      std::streamsize bytes_read = bin_file.gcount();
      std::cout << bytes_read << std::endl;
    } else {
      std::cerr << "No data found, closing.";
    }

  } else {
    std::cerr << "File not found, closing.";
  }

  return buffer;
}

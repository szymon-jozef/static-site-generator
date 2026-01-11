#include "io/io.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

std::string read_file(const std::string &FILE_PATH) {
  std::ifstream file(FILE_PATH);
  if (!file) {
    throw std::runtime_error("Error while opening file at " + FILE_PATH);
  }
  std::stringstream buffer;
  buffer << file.rdbuf();

  if (file.bad()) {
    throw std::runtime_error("Error while reading file at " + FILE_PATH);
  }

  return buffer.str();
}

void write_file(const std::string &FILE_PATH, const std::string &CONTENT) {
  std::ofstream out(FILE_PATH);
  if (!out) {
    throw std::runtime_error("Error while opening file for writing at " +
                             FILE_PATH);
  }

  out << CONTENT;

  if (!out) {
    throw std::runtime_error("Error while writing to the " + FILE_PATH);
  }

  out.close();
}

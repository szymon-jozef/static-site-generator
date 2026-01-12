#include "format/format.hpp"
#include "markdown/markdown.hpp"
#include <iostream>
#include <string>

static bool replace_once(std::string &str, const std::string &from,
                         const std::string &to) {
  size_t start_pos = str.find(from);
  if (start_pos == std::string::npos)
    return false;
  str.replace(start_pos, from.length(), to);
  return true;
}

std::string format_file(const std::string &TEMPLATE_FILE,
                        const std::string &TEMPLATE, const std::string &INPUT) {
  bool is_template = TEMPLATE_FILE.find(TEMPLATE) != std::string::npos;
  std::string result = TEMPLATE_FILE;

  if (!is_template) {
    std::clog << "There is no template in given file. Is this correct?"
              << std::endl;
    return result;
  }

  while (is_template) {
    is_template = replace_once(result, TEMPLATE, INPUT);
  }
  return result;
}

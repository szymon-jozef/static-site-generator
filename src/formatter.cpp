#include "markdown.hpp"
#include <fstream>
#include <sstream>
#include <string>

bool replace(std::string &str, const std::string &from, const std::string &to) {
  size_t start_pos = str.find(from);
  if (start_pos == std::string::npos)
    return false;
  str.replace(start_pos, from.length(), to);
  return true;
}

// Change template from file into html
// Return html in string
std::string inject_html_into_template(const std::string &FILE_NAME,
                                      const std::string &TEMPLATE,
                                      const std::string &HTML) {
  std::string result;
  std::ifstream file(FILE_NAME);
  if (!file.is_open()) {
    return "";
  }
  std::ostringstream ss;
  ss << file.rdbuf();
  result = ss.str();
  if (replace(result, TEMPLATE, HTML)) {
    return result;
  }
  return "";
}

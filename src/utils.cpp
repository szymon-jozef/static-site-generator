#include <set>
#include <sstream>
#include <string>

void trim(std::string &str) {
  str.erase(str.find_last_not_of(' ') + 1);
  str.erase(0, str.find_first_not_of(' '));
  str.erase(str.find_last_not_of('"') + 1);
  str.erase(0, str.find_first_not_of('"'));
}

std::set<std::string> convert_string_to_set(std::string input) {
  std::set<std::string> result;
  std::string buffer;
  size_t left, right;
  left = input.find_first_of('[');
  right = input.find_last_of(']');

  if (left == std::string::npos || right == std::string::npos ||
      right <= left) {
    return result;
  }

  input = input.substr(left + 1, right - left - 1);

  std::stringstream ss(input);

  while (getline(ss, buffer, ',')) {
    buffer.erase(0, buffer.find_first_not_of(" \t"));
    buffer.erase(buffer.find_last_not_of(" \t") + 1);

    if (buffer.size() >= 2 && buffer.front() == '"' && buffer.back() == '"') {
      buffer = buffer.substr(1, buffer.size() - 2);
      result.insert(buffer);
    }
  }

  return result;
}

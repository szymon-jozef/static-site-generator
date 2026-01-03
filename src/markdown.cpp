#include "markdown.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <md4c-html.h>
#include <optional>

std::optional<Metadata> get_metadata(const std::string &FILE_PATH) {
  std::fstream file(FILE_PATH);
  std::string buffer;

  if (!getline(file, buffer) || buffer != "---") {
    std::cerr << "File " << FILE_PATH << "does not contain metadata."
              << std::endl;
    return std::nullopt;
  }

  std::map<std::string, std::string> metadata_map;

  while (getline(file, buffer)) {
    if (buffer == "---") {
      break;
    }
    size_t colon_pos = buffer.find(":");

    if (colon_pos == std::string::npos) {
      std::cerr << "The line: \n"
                << buffer << " does not contain a colon" << std::endl;
    }

    std::string key = buffer.substr(0, colon_pos);
    trim(key);

    std::string value = buffer.substr(colon_pos + 1);
    trim(value);
    metadata_map[key] = value;
  }

  return std::optional(Metadata{metadata_map["author"], metadata_map["date"],
                                metadata_map["title"],
                                convert_string_to_set(metadata_map["tags"])});
}

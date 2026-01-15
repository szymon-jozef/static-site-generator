#pragma once
#include <ctime>
#include <optional>
#include <string>
#include <toml++/toml.hpp>
#include <vector>

struct Metadata {
  std::string author;
  time_t date;
  std::string title;
  std::vector<std::string> tags;
};

// Reads the metadata of the markdown file
// Metadata are in yaml format at the top of the file
// They are separated from the rest of the file with `---` at the beginning and
// at the end.
//
// Returns nullopt when no metadata is found in the file
std::optional<Metadata> get_metadata(const std::string &FILE_PATH);

// Reads the markdown file and converts it to html.
// Return everything in one string
std::string get_html(const std::string &FILE_PATH);

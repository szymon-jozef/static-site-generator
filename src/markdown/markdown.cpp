#include "markdown.hpp"
#include <ctime>
#include <iostream>
#include <map>
#include <md4c-html.h>
#include <optional>
#include <sstream>
#include <toml++/toml.hpp>

std::optional<Metadata> get_metadata(const std::string &FILE_CONTENTS) {
  std::stringstream file_contents(FILE_CONTENTS);
  std::stringstream metadata_s;
  std::string buffer;

  /* if there's no ---, then no metadata in file there is */
  if (!getline(file_contents, buffer) || buffer != "---") {
    std::clog << "File does not contain any metadata. Is this intentional?"
              << std::endl;
    return std::nullopt;
  }

  std::map<std::string, std::string> metadata_map;

  while (getline(file_contents, buffer)) {
    if (buffer == "---") {
      break;
    }
    metadata_s << buffer << '\n';
  }

  toml::table toml_table = toml::parse(metadata_s);
  std::vector<std::string> tags;
  const auto &toml_tags = toml_table["metadata"]["tags"];

  // translate toml into normal vector of strings
  if (toml_tags.is_array()) {
    for (auto iter = toml_tags.as_array()->begin();
         iter < toml_tags.as_array()->end(); iter++) {
      tags.emplace_back(static_cast<std::string>(iter->as_string()->get()));
    }
  }

  // time
  auto toml_time = toml_table["metadata"]["date"];

  struct tm t = {};
  time_t timestamp = time(NULL);

  if (toml_time.is_date()) {
    toml::date d = toml_time.as_date()->get();

    t.tm_year = d.year - 1900;
    t.tm_mon = d.month - 1;
    t.tm_mday = d.day;
    t.tm_isdst = 0;

    timestamp = mktime(&t);
  }

  Metadata metadata = {toml_table["metadata"]["author"].value_or(""), timestamp,
                       toml_table["metadata"]["title"].value_or(""), tags};

  return std::optional(metadata);
}

static void html_callback(const MD_CHAR *data, MD_SIZE size, void *userdata) {
  std::string *out = static_cast<std::string *>(userdata);
  out->append(data, size);
}

std::string get_html(const std::string &FILE_CONTENTS) {
  std::stringstream file_contents(FILE_CONTENTS);
  std::string buffer, file_string, out;
  getline(file_contents, buffer);
  bool is_metadata = buffer == "---";

  /* skip metadata */
  if (is_metadata) {
    while (getline(file_contents, buffer)) {
      if (buffer == "---") {
        break;
      }
    }
  } else {
    file_string += buffer + '\n';
  }

  while (getline(file_contents, buffer)) {
    file_string += buffer + '\n';
  }

  md_html(file_string.c_str(), file_string.size(), html_callback, &out, 0, 0);
  return out;
}

#pragma once
#include <string>

struct Contact {
  std::string author;
  std::string email;
  std::string signal;
};

struct Config {
  Contact contact;
};

Config get_config(const std::string &CONFIG_FILE);

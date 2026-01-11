#pragma once
#include <string>

struct Contact {
  std::string author;
  std::string email;
  std::string signal;
};

struct General {
  std::string lang;
  std::string title;
};

struct Config {
  Contact contact;
  General general;
};

Config get_config(const std::string &CONFIG_FILE);

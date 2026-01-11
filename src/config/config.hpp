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

// @brief Load config into `Config` struct
// @param CONFIGURATION content of `.toml` file containing configuration
// @return Config with parsed configuration
Config get_config(const std::string &CONFIGURATION);

#include "config.hpp"
#include <iostream>
#include <string>
#include <toml++/impl/parse_error.hpp>
#include <toml++/impl/parser.hpp>
#include <toml++/toml.hpp>

Config get_config(const std::string &CONFIGURATION) {
  toml::table toml_table;
  try {
    toml_table = toml::parse(CONFIGURATION);
  } catch (const toml::parse_error &err) {
    std::cerr << "Parsing failed:" << std::endl << err << std::endl;
  }

  Contact contact = {
      toml_table["contact"]["author"].value_or(""),
      toml_table["contact"]["email"].value_or(""),
      toml_table["contact"]["signal"].value_or(""),
  };

  General general = {
      toml_table["general"]["lang"].value_or(""),
      toml_table["general"]["title"].value_or(""),
  };

  Config config = {contact, general};

  return config;
}

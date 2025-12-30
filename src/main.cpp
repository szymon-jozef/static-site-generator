#include "config.hpp"
#include <iostream>
#include <string>

int main() { return 0; }

void test_config_read() {
  const std::string CONFIG_PATH = "../config/config_example.toml";
  Config config = get_config(CONFIG_PATH);
  std::cout << "Config" << std::endl;
  std::cout << "Author: " << config.contact.author << std::endl;
  std::cout << "Email: " << config.contact.email << std::endl;
  std::cout << "Signal: " << config.contact.signal << std::endl;
}

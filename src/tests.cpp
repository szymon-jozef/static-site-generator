#include "config.hpp"
#include <catch2/catch_all.hpp>
#include <string>

TEST_CASE("Checking config file read", "[config]") {
  const std::string FILE_NAME = "../config/config_example.toml";

  Config config = get_config(FILE_NAME);

  REQUIRE(config.contact.author == "author");
  REQUIRE(config.contact.email == "email@example.com");
  REQUIRE(config.contact.signal == "signal url");
}

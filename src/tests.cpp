#include "config.hpp"
#include "utils.hpp"
#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("Checking config file read", "[config]") {
  const std::string FILE_NAME = "../config/config_example.toml";

  Config config = get_config(FILE_NAME);

  REQUIRE(config.contact.author == "author");
  REQUIRE(config.contact.email == "email@example.com");
  REQUIRE(config.contact.signal == "signal url");
  REQUIRE(config.general.lang == "en");
  REQUIRE(config.general.title == "Blog");
}

TEST_CASE("convert_string_to_set parses inline YAML string list") {
  const std::string input = "[\"haha\", \"dupa\", \"xdd\"]";
  const std::set<std::string> output = {"haha", "dupa", "xdd"};
  REQUIRE(convert_string_to_set(input) == output);
}

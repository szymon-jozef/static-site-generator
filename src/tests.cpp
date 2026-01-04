#include "config.hpp"
#include "markdown.hpp"
#include "utils.hpp"
#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include <optional>
#include <string>

TEST_CASE("Checking config file read", "[config]") {
  const std::string FILE_NAME = "../examples/config.toml";

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

TEST_CASE("get_metadata function data correctness test") {
  const std::string FILE_NAME = "../examples/post.md";
  Metadata result = get_metadata(FILE_NAME).value();

  std::string expected_author = "joseph";
  std::string expected_date = "2026-01-01";
  std::string expected_title = "Example of a blog post";
  std::set<std::string> expected_tags = {"blog", "test", "lalilulelo"};

  REQUIRE(result.author == expected_author);
  REQUIRE(result.date == expected_date);
  REQUIRE(result.title == expected_title);

  for (const auto &tag : expected_tags) {
    REQUIRE(result.tags.count(tag));
  }
}

TEST_CASE("get_metadata function test with a file that doesn't have metadata") {
  const std::string FILE_NAME = "../examples/no_metadata_post.md";
  std::optional<Metadata> result = get_metadata(FILE_NAME);
  REQUIRE(result == std::nullopt);
}

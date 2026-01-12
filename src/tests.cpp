#include "config/config.hpp"
#include "format/format.hpp"
#include "io/io.hpp"
#include "markdown/markdown.hpp"
#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include <ctime>
#include <optional>
#include <string>

namespace TestFiles {
constexpr const char *config_toml = R"([general]
lang = "en"
title = "Blog"

[contact]
author = "author"
email = "email@example.com"
signal = "signal url"
)";

constexpr const char *formatter_html = R"(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    {{replace_me}}
</body>
</html>)";

constexpr const char *formated_html = R"(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    I'm formatted!
</body>
</html>)";

constexpr const char *no_metadata_post_md = R"(# This markdown has no metadata.
That's bad. Don't do it. It's for tests only.)";

constexpr const char *post_md = R"(---
[metadata]
author = "joseph"
date = 2026-01-01
title = "Example of a blog post"
tags = ["blog", "test", "lalilulelo"]
---
# This is an example post

In this example we will do a couple of cool markdown things.

## This is a h2 header
*This text is written in italic!*
### Look at this!
**This text is BOLD!**

## Hello world!
```cpp
#include <iostream>

int main() {
    std::cout << "Hello world!" << std::endl;
}
```
This is super cool!

## Time to link some random website!
This [should be clickable](https://example.com)

## Image test
![this should show an image](./image.png)

## This is an ordered list
1. one
2. six
3. seven

## This is an unordered one
- six
- nine
- six
- nine)";
} // namespace TestFiles

// IO tests
TEST_CASE("Test reading a file successful") {
  std::string result = read_file("./test_files/config.toml");
  REQUIRE(result == TestFiles::config_toml);
}

TEST_CASE("Test reading a file that doesn't exist") {
  REQUIRE_THROWS(read_file("this/path/doesnt/exist"));
}

// Config tests

TEST_CASE("Checking config file read", "[config]") {
  Config config = get_config(TestFiles::config_toml);

  REQUIRE(config.contact.author == "author");
  REQUIRE(config.contact.email == "email@example.com");
  REQUIRE(config.contact.signal == "signal url");
  REQUIRE(config.general.lang == "en");
  REQUIRE(config.general.title == "Blog");
}

// Markdown tests

TEST_CASE("get_metadata function data correctness test") {
  Metadata result = get_metadata(TestFiles::post_md).value();

  std::string expected_author = "joseph";
  struct tm datetime = {0};
  datetime.tm_year = 2026 - 1900;
  datetime.tm_mon = 1 - 1;
  datetime.tm_mday = 1;
  datetime.tm_isdst = 0;

  time_t expected_date = mktime(&datetime);
  std::string expected_title = "Example of a blog post";
  std::vector<std::string> expected_tags = {"blog", "test", "lalilulelo"};

  REQUIRE(result.author == expected_author);
  REQUIRE(result.date == expected_date);
  REQUIRE(result.title == expected_title);
  REQUIRE(result.tags == expected_tags);
}

TEST_CASE("get_metadata function test with a file that doesn't have metadata") {
  std::optional<Metadata> result = get_metadata(TestFiles::no_metadata_post_md);
  REQUIRE(result == std::nullopt);
}

TEST_CASE("get_html function parsing test") {
  const std::string EXPECTED_OUTPUT =
      R"HTML(<h1>This is an example post</h1>
<p>In this example we will do a couple of cool markdown things.</p>
<h2>This is a h2 header</h2>
<p><em>This text is written in italic!</em></p>
<h3>Look at this!</h3>
<p><strong>This text is BOLD!</strong></p>
<h2>Hello world!</h2>
<pre><code class="language-cpp">#include &lt;iostream&gt;

int main() {
    std::cout &lt;&lt; &quot;Hello world!&quot; &lt;&lt; std::endl;
}
</code></pre>
<p>This is super cool!</p>
<h2>Time to link some random website!</h2>
<p>This <a href="https://example.com">should be clickable</a></p>
<h2>Image test</h2>
<p><img src="./image.png" alt="this should show an image"></p>
<h2>This is an ordered list</h2>
<ol>
<li>one</li>
<li>six</li>
<li>seven</li>
</ol>
<h2>This is an unordered one</h2>
<ul>
<li>six</li>
<li>nine</li>
<li>six</li>
<li>nine</li>
</ul>
)HTML";

  REQUIRE(get_html(TestFiles::post_md) == EXPECTED_OUTPUT);
}

// Format tests
TEST_CASE("Test format_file function with correct data") {
  REQUIRE(TestFiles::formated_html == format_file(TestFiles::formatter_html,
                                                  "{{replace_me}}",
                                                  "I'm formatted!"));
}

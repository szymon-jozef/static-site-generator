#include "../config.hpp"
#include "../markdown.hpp"
#include "../utils.hpp"
#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include <ctime>
#include <optional>
#include <string>

TEST_CASE("Checking config file read", "[config]") {
  const std::string FILE_NAME = "tests/config.toml";

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
  const std::string FILE_NAME = "./tests/post.md";
  Metadata result = get_metadata(FILE_NAME).value();

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
  const std::string FILE_NAME = ".tests/no_metadata_post.md";
  std::optional<Metadata> result = get_metadata(FILE_NAME);
  REQUIRE(result == std::nullopt);
}

TEST_CASE("get_html function parsing test") {
  const std::string INPUT = "./tests/post.md";
  const std::string EXPECTED_OUTPUT = R"HTML(<h1>This is an example post</h1>
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

  REQUIRE(get_html(INPUT) == EXPECTED_OUTPUT);
}

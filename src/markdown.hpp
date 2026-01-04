#include <optional>
#include <set>
#include <string>

struct Metadata {
  std::string author;
  std::string date;
  std::string title;
  std::set<std::string> tags;
};

// Reads the metadata of the markdown file
// Metadata are in yaml format at the top of the file
// They are separated from the rest of the file with `---` at the beginning and
// at the end.
//
// Returns nullopt when no metadata is found in the file
std::optional<Metadata> get_metadata(const std::string &FILE_PATH);

// Reads the markdown file and converts it to html.
// Return everything in one string
std::string get_html(const std::string &FILE_PATH);

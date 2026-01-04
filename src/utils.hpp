#include <set>
#include <string>

// trim string in-place, removing all whitespaces and surrounding '"' symbols
void trim(std::string &str);

// Convert a string containing an inline YAML/JSON-style list of strings
// into a std::set<std::string>.
//
// Supported format (single line):
//   ["haha", "dupa", "xdd"]
//
// Limitations:
// - no nested structures
// - no escaping inside strings
// - elements must be quoted
//
// Example:
//   Input:  ["haha", "dupa", "xdd"]
//   Output: {"dupa", "haha", "xdd"}   // sorted, unique
std::set<std::string> convert_string_to_set(std::string input);

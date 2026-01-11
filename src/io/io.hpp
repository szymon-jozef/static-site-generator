#include <string>

// @brief Read file from given path
// @param FILE PATH Path to the file
// @return File content
// @throws std::runtime_error if any errors
std::string read_file(const std::string &FILE_PATH);

/// @brief Writes the given content into a file.
/// @param FILE_PATH Path to the file to write.
/// @param CONTENT Content to write into the file.
/// @throws std::runtime_error if the file cannot be opened or written.
void write_file(const std::string &FILE_PATH, const std::string &CONTENT);

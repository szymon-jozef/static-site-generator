#include <string>

// @brief Format file.
// @param TEMPLATE_FILE File that you want to format in string.
// @param TEMPLATE Template that you want to replace. For example `{{title}}`
// @param INPUT Text that you want to replace TEMPLATE with.
// @return Formatted file in std::string
std::string format_file(const std::string &TEMPLATE_FILE,
                        const std::string &TEMPLATE, const std::string &INPUT);

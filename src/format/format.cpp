#include "format/format.hpp"
#include "markdown/markdown.hpp"
#include <iostream>
#include <string>

// Replace TEMPLATE with REPLACMENT in-place
static bool replace_once_global(std::string &STR, const std::string &TEMPLATE,
                                const std::string &REPLACMENT) {
  size_t start_pos = STR.find(TEMPLATE);
  if (start_pos == std::string::npos) {
    return false;
  }
  STR.replace(start_pos, TEMPLATE.length(), REPLACMENT);
  return true;
}

// Replace TEMPLATE with REPLACMENT between starting from `start`
static bool replace_once_between(std::string &STR, const std::string &TEMPLATE,
                                 const std::string &REPLACMENT,
                                 const size_t &START) {
  size_t start_pos = STR.find(TEMPLATE, START);
  if (start_pos == std::string::npos) {
    return false;
  }
  STR.replace(start_pos, TEMPLATE.length(), REPLACMENT);
  return true;
}

// Remove everything from START to STOP
static bool remove_from_to(std::string &STR, const std::string &START,
                           const std::string &STOP) {
  size_t start_pos = STR.find(START);
  if (start_pos == std::string::npos) {
    return false;
  }

  size_t stop_pos = STR.find(STOP, start_pos);
  if (stop_pos == std::string::npos) {
    return false;
  }

  STR.replace(start_pos, stop_pos - start_pos + STOP.length(), "");
  return true;
}

std::string format_file(const std::string &TEMPLATE_FILE,
                        const std::string &TEMPLATE, const std::string &INPUT) {
  bool is_template = TEMPLATE_FILE.find(TEMPLATE) != std::string::npos;
  std::string result = TEMPLATE_FILE;

  if (!is_template) {
    std::clog << "There is no template in given file. Is this correct?"
              << std::endl;
    return result;
  }

  while (is_template) {
    is_template = replace_once_global(result, TEMPLATE, INPUT);
  }
  return result;
}

std::string format_file_condtionally(const std::string &TEMPLATE_FILE,
                                     const std::string &TEMPLATE,
                                     const std::string &INPUT) {

  size_t template_pos = TEMPLATE_FILE.find(TEMPLATE);
  bool is_template = template_pos != std::string::npos;

  std::string result = TEMPLATE_FILE;

  if (!is_template) {
    std::clog << "There is no template in given file. Is this correct?"
              << std::endl;
    return result;
  }

  // if template is empty then we remove everything in between
  if (TEMPLATE == "") {
    while (is_template) {
      is_template = remove_from_to(result, TEMPLATE, "{{endif}");
    }
  }

  while (is_template) {
    is_template =
        replace_once_between(result, TEMPLATE, INPUT, result.find(TEMPLATE));
  }
  return result;
}

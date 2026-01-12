#include "format/format.hpp"
#include "markdown/markdown.hpp"
#include <string>

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
  std::string result = TEMPLATE_FILE;
  size_t current_pos = 0;

  while (true) {
    size_t found_pos = result.find(TEMPLATE, current_pos);

    if (found_pos == std::string::npos) {
      break;
    }

    result.replace(found_pos, TEMPLATE.length(), INPUT);
    current_pos = found_pos + INPUT.length();
  }
  return result;
}

std::string format_file_conditionally(const std::string &TEMPLATE_FILE,
                                      const std::string &START_TAG,
                                      const std::string &END_TAG,
                                      const std::string &TEMPLATE,
                                      const std::string &INPUT) {
  std::string result = TEMPLATE_FILE;

  if (INPUT.empty()) {
    while (true) {
      if (!remove_from_to(result, START_TAG, END_TAG)) {
        break;
      }
    }
  } else {
    // remove START tag
    size_t pos = 0;
    while ((pos = result.find(START_TAG, pos)) != std::string::npos) {
      result.replace(pos, START_TAG.length(), "");
    }

    // remove END tag
    pos = 0;
    while ((pos = result.find(END_TAG, pos)) != std::string::npos) {
      result.replace(pos, END_TAG.length(), "");
    }

    // replace
    result = format_file(result, TEMPLATE, INPUT);
  }

  return result;
}

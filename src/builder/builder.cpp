#include "builder/builder.hpp"
#include "config/config.hpp"
#include "format/format.hpp"

std::string build_index(const std::string &TEMPLATE, const Page &PAGE,
                        const Information &INFORMATION) {
  std::string result = TEMPLATE;
  result = format_file(result, "{{lang}}", INFORMATION.config.general.lang);
  result = format_file(result, "{{head}}", PAGE.head);
  result = format_file(result, "{{header}}", PAGE.header);
  result = format_file(result, "{{main}}", PAGE.main);
  result = format_file(result, "{{footer}}", PAGE.footer);
  return result;
}

std::string build_header(const std::string &TEMPLATE,
                         const Information &INFORMATION) {
  std::string result =
      format_file(TEMPLATE, "{{title}}", INFORMATION.metadata.title);
  ;

  return result;
}

std::string build_head(const std::string &TEMPLATE,
                       const Information &INFORMATION) {
  std::string result =
      format_file(TEMPLATE, "{{title}}", INFORMATION.metadata.title);
  return result;
}

std::string build_footer(const std::string &TEMPLATE,
                         const Information &INFORMATION) {
  std::string result = TEMPLATE;
  result =
      format_file_conditionally(result, "{{if email}}", "{{endif}}",
                                "{{email}}", INFORMATION.config.contact.email);

  result = format_file_conditionally(result, "{{if signal}}", "{{endif}}",
                                     "{{signal}}",
                                     INFORMATION.config.contact.signal);
  return result;
}

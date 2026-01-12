#include "config/config.hpp"
#include "markdown/markdown.hpp"

struct Page {
  std::string head;
  std::string header;
  std::string main;
  std::string footer;
};

struct Information {
  Config config;
  Metadata metadata;
};

// @brief Function that builds index.html. It takes all the information from
// `Page` struct that should be built before calling it.
// @param TEMPLATE Template file that will be used to build index
// @param PAGE Page struct with information on html tags
// @return Built index.html in string
std::string build_index(const std::string &TEMPLATE, const Page &PAGE,
                        const Information &INFORMATION);

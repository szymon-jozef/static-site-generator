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

// @brief Function that builds particular blog entry. It takes all it's
// information flog `Page struct` that should be built before calling it.
// @param TEMPLATE Template file for blog
// @param PAGE Page struct with information on blog entry content
// @param INFORMATION Information metadata about config and metadata of the file
// @return Built blog_entry.html in string
std::string build_blog_entry(const std::string &TEMPLATE, const Page &BLOG,
                             const Information &INFORMATION);

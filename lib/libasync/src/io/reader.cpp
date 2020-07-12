/**
 * @file reader.cpp
 * @brief Implementation of the class "Reader".
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#include "reader.hpp"
#include <istream>

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the IO */
namespace io {

reader::reader(std::istream& istrm) noexcept : istrm_{istrm} {}

reader::~reader() noexcept {}

void reader::read_cycle() {
  for (std::string tmp_str{""}; std::getline(istrm_, tmp_str);) {
    if (!tmp_str.empty())
      notify(tmp_str);
  }
}

} /* io:: */
} /* bulkmt:: */

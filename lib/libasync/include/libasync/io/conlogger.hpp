/**
 * @file conlogger.hpp
 * @brief Discription of the "Console Logger" class.
 *
 * @details
 * Class for logging data to the console.
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#ifndef CONLOGGER_HPP_
#define CONLOGGER_HPP_

#include <ostream>
#include <string>

#include <libasync/common/counter.hpp>
#include <libasync/io/ilogger.hpp>

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the IO */
namespace io {

/** @brief Logger for print bulk in file and console. */
class conlogger final : public bulkmt::io::ilogger {
  std::ostream& ostrm_;
  std::string str_;
  bulkmt::common::counter cnt_;

public:
  /**
   * @brief The construcor.
   * @param [in] ostrm - ref on console.
   * @param [in] str - text to output to the log.
   * @param [in] cnt - counter for accounting.
   */
  explicit conlogger(std::ostream& ostrm, const std::string& str,
                     const bulkmt::common::counter& cnt) noexcept;

  /** @brief The default distructor. */
  virtual ~conlogger() noexcept override;

  /**
   * @brief start
   * @return Counter for accounting.
   */
  virtual bulkmt::common::counter start() noexcept override;
};

} /* io:: */
} /* bulkmt:: */

#endif /* CONLOGGER_HPP_ */

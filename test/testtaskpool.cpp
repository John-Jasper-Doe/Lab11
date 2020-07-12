#include <gtest/gtest.h>
#include <ostream>
#include "common/counter.hpp"
#include "common/taskpool.hpp"
#include "io/ilogger.hpp"

class test_loger : public bulkmt::io::ilogger {
  std::ostream& ostrm_;
  std::string str_;
  bulkmt::common::counter cnt_;

public:
  explicit test_loger(std::ostream& ostrm, const std::string& str,
                      const bulkmt::common::counter& cnt) noexcept
    : ostrm_(ostrm), str_(std::move(str)), cnt_(cnt) {}

  virtual ~test_loger() noexcept override {}

  bulkmt::common::counter start() noexcept override {
    ostrm_ << str_ << '\n';
    return cnt_;
  }
};

TEST(test_taskpool, test_taskpool1) {
  std::stringstream ss;
  bulkmt::common::taskpool<3> tp("group_test");
  tp.start();

  bulkmt::common::counter cnt1;
  bulkmt::common::counter cnt2;
  bulkmt::common::counter cnt3;
  bulkmt::common::counter cnt4;

  cnt1.inc_blk();
  cnt2.inc_str();
  cnt3.inc_cmd();
  cnt4.inc_blk();
  cnt4.inc_blk();
  cnt2.inc_blk();

  test_loger lg1(ss, "logger1", cnt1);
  test_loger lg2(ss, "logger2", cnt2);
  test_loger lg3(ss, "logger3", cnt3);
  test_loger lg4(ss, "logger4", cnt4);

  tp.push([&lg1]() { return lg1.start(); });
  tp.push([&lg2]() { return lg2.start(); });
  tp.push([&lg3]() { return lg3.start(); });
  tp.push([&lg4]() { return lg4.start(); });

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(2s);

  tp.stop();

  std::string expected{"All count from pool: 1 commands, 4 blocks\n"};
  std::string str = tp.count_all_as_str();
  //  std::cout << str << std::endl;
  ASSERT_EQ(str, expected);
}

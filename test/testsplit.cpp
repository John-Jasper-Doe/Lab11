#include <gtest/gtest.h>
#include <regex>
#include <string>

namespace {

std::vector<std::string> split(const std::string& str) {
  std::regex ws_re("\\n+");
  return std::vector<std::string>{std::sregex_token_iterator(str.begin(), str.end(), ws_re, -1),
                                  std::sregex_token_iterator()};
}

} /* :: */

TEST(test_split, test_split_six_elem) {
  std::vector<std::string> res = split("0\n0\n0\n0\n0\n0\n");
  std::vector<std::string> expected{"0", "0", "0", "0", "0", "0"};

  ASSERT_TRUE(res.size() == expected.size());
  ASSERT_TRUE(std::equal(res.begin(), res.end(), expected.begin()));
}

TEST(test_split, test_split_one_elem) {
  std::vector<std::string> res = split("1\n");
  std::vector<std::string> expected{"1"};

  ASSERT_TRUE(res.size() == expected.size());
  ASSERT_TRUE(std::equal(res.begin(), res.end(), expected.begin()));
}

TEST(test_split, test_split_one_elem_without_seporator) {
  std::vector<std::string> res = split("1");
  std::vector<std::string> expected{"1"};

  ASSERT_TRUE(res.size() == expected.size());
  ASSERT_TRUE(std::equal(res.begin(), res.end(), expected.begin()));
}

TEST(test_split, test_split_sep_beg_end) {
  std::vector<std::string> res = split("\n2\n3\n4\n5\n6\n{\na\n");
  std::vector<std::string> expected{"", "2", "3", "4", "5", "6", "{", "a"};

  ASSERT_TRUE(res.size() == expected.size());
  ASSERT_TRUE(std::equal(res.begin(), res.end(), expected.begin()));
}

TEST(test_split, test_split_sep_end) {
  std::vector<std::string> res = split("b\nc\nd\n}\n89\n");
  std::vector<std::string> expected{"b", "c", "d", "}", "89"};

  ASSERT_TRUE(res.size() == expected.size());
  ASSERT_TRUE(std::equal(res.begin(), res.end(), expected.begin()));
}

TEST(test_split, test_split_sep_end_2) {
  std::vector<std::string> res = split("1\n2\n3\n4\n5\n6\n");
  std::vector<std::string> expected{"1", "2", "3", "4", "5", "6"};

  ASSERT_TRUE(res.size() == expected.size());
  ASSERT_TRUE(std::equal(res.begin(), res.end(), expected.begin()));
}

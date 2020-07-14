/**
 * @file context.cpp
 * @brief Implimentation of the class "Context".
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#include <iostream>
#include <ostream>

#include <libasync/common/split.hpp>
#include <libasync/core/context.hpp>
#include <libasync/io/tsreader.hpp>

/** @brief The namespace of the Async Library project */
namespace libasync {
/** @brief The namespace of the Core */
namespace core {

context::context(std::size_t cmd_per_block) noexcept
  : ostrm_stat_{std::cout}, ostrm_log_{std::cout} {
  std::unique_ptr<io::ireader> rd = std::make_unique<io::tsreader>(queue_);
  std::shared_ptr<core::controller> controller_ =
      std::make_shared<core::controller>(cmd_per_block, std::move(rd), ostrm_stat_, ostrm_log_);

  auto l_func = [this]() { this->controller_->start(); };
  worker_ = thread_ptr_t(new std::thread(l_func), [](std::thread* t) { t->join(); });
}

void context::input(const std::string& str) {
  std::vector<std::string> lines = common::split(str);

  for (std::string& line : lines) {
    queue_.push(std::move(line));
  }
}

} /* core:: */
} /* libasync:: */

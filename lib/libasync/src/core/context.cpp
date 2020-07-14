/**
 * @file context.cpp
 * @brief Implimentation of the class "Context".
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#include <libasync/core/context.hpp>

/** @brief The namespace of the Async Library project */
namespace libasync {
/** @brief The namespace of the Core */
namespace core {

context::context(std::size_t cmd_per_block) noexcept
  : cmd_per_block_{cmd_per_block} { }

void context::input(const std::string&) {

}

} /* core:: */
} /* libasync:: */

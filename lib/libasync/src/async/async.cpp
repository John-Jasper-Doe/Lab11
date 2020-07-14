/**
 * @file async.cpp
 * @brief Async functions for work with library..
 *
 * @date 2020
 */

#include <memory>
#include <map>
#include <mutex>

#include <libasync/async/async.hpp>
#include <libasync/core/context.hpp>

/** @brief The namespace of the Async Library project */
namespace libasync {
/** @brief The namespace of the Async */
namespace async {

using raw_context_ptr_t = core::context*;
using context_ptr_t = std::unique_ptr<core::context>;

namespace {

/* Context */
static std::map<raw_context_ptr_t, context_ptr_t> contexts;
static std::mutex mtx;

} /* :: */

handle_t connect(std::size_t bulk) {
  context_ptr_t ptr = std::make_unique<core::context>(bulk);
  raw_context_ptr_t raw_ptr = ptr.get();

  std::unique_lock<std::mutex> lock(mtx);
  contexts.emplace(std::make_pair(raw_ptr, std::move(ptr)));
  lock.unlock();

  return reinterpret_cast<handle_t>(raw_ptr);
}

void receive(handle_t handle, const char* data, std::size_t size) {
  (void)handle;
  (void)data;
  (void)size;
}

void disconnect(handle_t handle) {
  (void)handle;
}

} /* async:: */
} /* libasync:: */

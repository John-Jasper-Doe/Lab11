# CMake file for test directory

set(CMAKE_FOLDER "${CMAKE_FOLDER}/test")

set(PROJECT_SRC
  ${CMAKE_SOURCE_DIR}/src/common/cmdpool.cpp
  ${CMAKE_SOURCE_DIR}/src/common/counter.cpp
  ${CMAKE_SOURCE_DIR}/src/io/reader.cpp
)

addtest("alltests"
#  reader.cpp
  testreader.cpp
  testcmdpool.cpp
  testcounter.cpp
  testtsqueue.cpp
  testtaskpool.cpp
  ${PROJECT_SRC}
)

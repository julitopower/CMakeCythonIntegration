##
# The MIT License (MIT)
#
# Copyright (c) 2014, 2018 Julio Delgado

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the right
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
##
set(CTEST_CUSTOM_WARNING_EXCEPTION ${CTEST_CUSTOM_WARNING_EXCEPTION}
  # http://public.kitware.com/Bug/view.php?id=10179
  "ld: warning: duplicate dylib")
include(CTest)

add_definitions(-DBOOST_TEST_DYN_LINK) # generates main() for unit tests

include_directories(${CMAKE_CURRENT_SOURCE_DIR}) ### for tests headers ###
include_directories(${CMAKE_SOURCE_DIR}/src/)
include_directories(${CMAKE_BINARY_DIR}) ### for config.h ###

# Libraries to link the tests executables with
set(TESTS_LIBRARIES
  ${Boost_LIBRARIES}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  StdoutWriter
  Adder
)

# Create all the tests
set(TEST_FILES AdderTests.cpp StdoutWriterTest.cpp)
set(ALL_TESTS)
foreach(FILE ${TEST_FILES})
  string(REGEX REPLACE ".cpp" "" NAME ${FILE})
  string(REGEX REPLACE "[./]" "_" NAME ${NAME})

  add_executable(${NAME} ${FILE})
  #set_target_properties(${NAME} PROPERTIES FOLDER "Tests")

  target_link_libraries(${NAME} ${TESTS_LIBRARIES})

#  get_target_property(EXECUTABLE ${NAME} LOCATION)
#  STRING(REGEX REPLACE "\\$\\(.*\\)" "\${CTEST_CONFIGURATION_TYPE}"
#         EXECUTABLE "${EXECUTABLE}")

  add_test(${NAME} ${NAME})
  list(APPEND ALL_TESTS ${NAME})
endforeach()

# workaround bug that tests won't get built
# add_custom_target(tests COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS ${ALL_TESTS})
# set_target_properties(tests PROPERTIES FOLDER "Tests")

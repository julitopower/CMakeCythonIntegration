/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014, 2018 Julio Delgado

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/
#define BOOST_TEST_MODULE AdderTest
#include <boost/test/unit_test.hpp>

#include <Adder.hpp>

namespace {
  std::string  valid_json_1 = "{\"numbers\" : [2,2]}";
  std::string  valid_json_2 = "{\"numbers\" : [\"2\",\"3\"]}";
}

BOOST_AUTO_TEST_CASE( TestValidJson )
{
  Adder adder;
  int result = adder.add(valid_json_1);
  BOOST_CHECK_EQUAL(4, result);

  result = adder.add(valid_json_2);
  BOOST_CHECK_EQUAL(5, result);
}

BOOST_AUTO_TEST_CASE( TestEmptyJson )
{
  Adder adder;
  int result = adder.add("{}");
  BOOST_CHECK_EQUAL(0, result);
}

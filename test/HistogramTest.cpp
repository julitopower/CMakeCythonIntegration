/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Julio Delgado

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
#define BOOST_TEST_MODULE HistogramTests
#include <boost/test/unit_test.hpp>

#include <Histogram.hpp>

BOOST_AUTO_TEST_CASE( TestAfterWinCountIs1 )
{
  probability::Histogram h;
  std::string event = "julio";
  h.addWin(event);
  BOOST_CHECK_EQUAL(h.getCount(event), 1);
}

BOOST_AUTO_TEST_CASE( TestAfterWinWinCountIs2 )
{
  probability::Histogram h;
  std::string event = "julio";
  h.addWin(event);
  h.addWin(event);
  BOOST_CHECK_EQUAL(h.getCount(event), 2);
}

BOOST_AUTO_TEST_CASE( TestUnknownEventCountIs0 )
{
  probability::Histogram h;
  std::string event = "julio";
  h.addWin(event);
  BOOST_CHECK_EQUAL(h.getCount("what"), 0);
}

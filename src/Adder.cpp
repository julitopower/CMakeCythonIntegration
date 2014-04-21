#include "Adder.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <sstream>
#include <iostream>

Adder::Adder(){}

int Adder::add(const std::string & json) const {
  using boost::property_tree::ptree;
  ptree tree;
  std::stringstream ss;
  ss << json;

  // Here goes the processing
  int acum = 0;
  try {
    read_json(ss, tree);
    BOOST_FOREACH(ptree::value_type & v , tree.get_child("numbers")) {
      acum += v.second.get_value<int>();
    }
  } catch(...) {
    return 0;
  }
  return acum;
}

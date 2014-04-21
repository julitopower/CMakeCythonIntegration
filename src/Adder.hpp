#ifndef ADDER_H
#define ADDER_H

#include <string>

class Adder {
public:
  Adder();
  int add(const std::string & json) const;
};

#endif //ADDER_H

#ifndef STDOUT_WRITER_H
#define STDOUT_WRITER_H

#include <iostream>
#include <string>

class StdoutWriter {
public:
  StdoutWriter();
  StdoutWriter(const std::string & message);
  void repeat();
  void write(const std::string & message);
private:
  std::string _message;
};

#endif //STDOUT_WRITER_H

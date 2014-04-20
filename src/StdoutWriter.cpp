#include "StdoutWriter.hpp"

StdoutWriter::StdoutWriter() : _message() {}

StdoutWriter::StdoutWriter(const std::string & message) : _message(message) {}

void StdoutWriter::repeat() {
  std::cout << _message << std::endl;
}
void StdoutWriter::write(const std::string & message) {
  _message = message;
  repeat();
}

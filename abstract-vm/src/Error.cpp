#include "Error.hpp"

Error::Error() {}
Error::Error(char* const str) : _message(str) {}
Error::Error(std::string const &str) : _message(str) {}
Error::~Error() noexcept { exit(0); }
const char *Error::what() const throw() { return _message.c_str(); }

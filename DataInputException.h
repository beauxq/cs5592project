// exception to specify wrong format of input data

#ifndef CS5592PROJECT_DATAFORMATEXCEPTION_H
#define CS5592PROJECT_DATAFORMATEXCEPTION_H

#include <stdexcept>
#include <string>

class DataInputException: public std::runtime_error
{
public:
    DataInputException(const std::string& what_arg) : std::runtime_error(what_arg) {};
    DataInputException(const char* what_arg) : std::runtime_error(what_arg) {};
};

#endif //CS5592PROJECT_DATAFORMATEXCEPTION_H

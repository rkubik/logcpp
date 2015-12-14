#ifndef _LOGCPP_HELPERS_EXCEPTION_HPP_
#define _LOGCPP_HELPERS_EXCEPTION_HPP_

#include <string>
#include <exception>

namespace logcpp {

namespace helpers {

class LogcppException : public std::exception {
private:
    std::string m_msg;

public:
    LogcppException(const std::string &msg);
    ~LogcppException() throw();
    const char *what() const throw();
};

};

};

#endif
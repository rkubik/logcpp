#include <logcpp/helpers/exception.hpp>
using namespace logcpp;
using namespace logcpp::helpers;

using namespace std;

LogcppException::LogcppException(const string &msg) : m_msg(msg)
{
}

LogcppException::~LogcppException() throw()
{
}

const char *LogcppException::what() const throw()
{
    return m_msg.c_str();
}

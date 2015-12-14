#ifndef _LOGCPP_LOGGER_CONSOLELOGGER_HPP_
#define _LOGCPP_LOGGER_CONSOLELOGGER_HPP_

#include <logcpp/logger/streamlogger.hpp>

namespace logcpp {

class ConsoleLogger : public StreamLogger
{
public:
    OBJECT_PTR(ConsoleLogger);

    ConsoleLogger();
    virtual ~ConsoleLogger();
};

};

#endif

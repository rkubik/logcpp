#ifndef _LOGCPP_LOGGER_SYSLOGGER_HPP_
#define _LOGCPP_LOGGER_SYSLOGGER_HPP_

#include <logcpp/logger.hpp>

namespace logcpp {

class SyslogLogger : public Logger
{
public:
    OBJECT_PTR(SyslogLogger);

    SyslogLogger();
    virtual ~SyslogLogger();

protected:
    void ProcessLogEntry(const LogEntry& entry) override;
};

};

#endif

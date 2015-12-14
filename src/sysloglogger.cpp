#include <logcpp/logger/sysloglogger.hpp>
using namespace logcpp;

#include <syslog.h>

SyslogLogger::SyslogLogger()
{
}

SyslogLogger::~SyslogLogger()
{
}

void SyslogLogger::ProcessLogEntry(const LogEntry& entry)
{
    int severity;
    switch (entry.Severity) {
        case LogDebug:
            severity = LOG_DEBUG;
            break;
        case LogNotice:
            severity = LOG_NOTICE;
            break;
        case LogWarning:
            severity = LOG_WARNING;
            break;
        case LogCritical:
            severity = LOG_CRIT;
            break;
        case LogInformation:
        default:
            severity = LOG_INFO;
            break;
    }

    syslog(severity | LOG_USER, "%s", entry.Message.c_str());
}

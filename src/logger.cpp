#include <logcpp/logger.hpp>
#include <logcpp/helpers/exception.hpp>
#include <logcpp/helpers/utility.hpp>
#include <logcpp/formatter/basicformatter.hpp>
using namespace logcpp;
using namespace logcpp::helpers;
using namespace std;

set<Logger::Ptr> Logger::m_Loggers;
mutex Logger::m_LMutex;

Logger::Logger(void)
:
m_Severity(LogCritical),
m_Formatter(new BasicFormatter())
{
}

Logger::~Logger(void)
{
}

mutex& Logger::GetLock(void)
{
    return m_Mutex;
}

string Logger::GetName(void) const
{
    return m_Name;
}

void Logger::SetFormatter(Formatter::Ptr format)
{
    m_Formatter = format;
}

void Logger::SetName(const string name)
{
    m_Name = name;
}

LogSeverity Logger::GetSeverity(void) const
{
    return m_Severity;
}

void Logger::SetSeverity(LogSeverity severity)
{
    m_Severity = severity;
}

string Logger::SeverityToString(LogSeverity severity)
{
    switch (severity) {
        case LogDebug:
            return "debug";
        case LogNotice:
            return "notice";
        case LogInformation:
            return "information";
        case LogWarning:
            return "warning";
        case LogCritical:
            return "critical";
        default:
            throw LogcppException("Invalid severity");
    }
}

LogSeverity Logger::StringToSeverity(const string& severity)
{
    if (severity == "debug")
        return LogDebug;
    else if (severity == "notice")
        return LogNotice;
    else if (severity == "information")
        return LogInformation;
    else if (severity == "warning")
        return LogWarning;
    else if (severity == "critical")
        return LogCritical;
    else
        throw LogcppException("Invalid severity");
}

Logger::Ptr Logger::GetLogger(const string& loggerName)
{
    for(const Logger::Ptr& logger : Logger::GetLoggers()) {
        lock_guard<mutex> lock(logger->GetLock());

        if (logger->GetName() == loggerName) {
            return logger;
        }
    }
    return nullptr;
}

set<Logger::Ptr> Logger::GetLoggers(void)
{
    lock_guard<mutex> lock(m_LMutex);
    return m_Loggers;
}

void Logger::AddLogger(Logger::Ptr logger)
{
    lock_guard<mutex> lock(m_LMutex);
    m_Loggers.insert(logger);
}

void Logger::RemoveLogger(const string& loggerName)
{
    lock_guard<mutex> lock(m_LMutex);
    auto loggerIdx = begin(m_Loggers);

    while (loggerIdx != end(m_Loggers)) {
        lock_guard<mutex> lock((*loggerIdx)->GetLock());

        if ((*loggerIdx)->GetName() == loggerName) {
            loggerIdx = m_Loggers.erase(loggerIdx);
        } else {
            ++loggerIdx;
        }
    }
}

void Logger::Print(LogEntry entry)
{
    entry.Timestamp = Utility::GetTime();

    for(const Logger::Ptr& logger : Logger::GetLoggers()) {
        lock_guard<mutex> lock(logger->GetLock());

        if (entry.Severity >= logger->GetSeverity()) {
            logger->ProcessLogEntry(entry);
        }
    }
}

#ifndef _LOGCPP_LOGGER_HPP_
#define _LOGCPP_LOGGER_HPP_

#include <logcpp/formatter/formatter.hpp>

#include <string>
#include <sstream>
#include <set>
#include <mutex>
#include <memory>

namespace logcpp {

// Log with context
#define LOG(s) Log(s).Context(__LINE__, __FUNCTION__, __FILE__)
// Log helpers with context
#define LOG_DEBUG LOG(logcpp::LogDebug)
#define LOG_NOTICE LOG(logcpp::LogNotice)
#define LOG_INFO LOG(logcpp::LogInformation)
#define LOG_WARN LOG(logcpp::LogWarning)
#define LOG_ERROR LOG(logcpp::LogError)
#define LOG_CRIT LOG(logcpp::LogCritical)

enum LogSeverity
{
    LogDebug,
    LogNotice,
    LogInformation,
    LogWarning,
    LogError,
    LogCritical,
    LogOff
};

struct LogEntry {
    double Timestamp;
    LogSeverity Severity;
    std::string Facility;
    std::string Message;
    int Line = 0;
    std::string Function;
    std::string File;
};

class Logger
{
public:
    OBJECT_PTR(Logger);

    virtual ~Logger(void);

    /**
     * Return logger lock reference.
     *
     * @return Logger lock.
     */
    std::mutex& GetLock(void);

    /**
     * Return logger severity.
     *
     * @return Minimum logger severity
     */
    LogSeverity GetSeverity(void) const;

    /**
     * Return logger name.
     *
     * @return Logger name
     */
    std::string GetName(void) const;

    /**
     * Set minimum logger severity. Any messages higher than this severity will
     * be discarded (no output).
     *
     * @param severity Logger severity
     */
    void SetSeverity(LogSeverity severity);

    /**
     * Set logger name.
     *
     * @param name Logger name
     */
    void SetName(const std::string name);

    /**
     * Set log formatter.
     *
     * @param format Log formatter
     */
    void SetFormatter(Formatter::Ptr format);

    /**
     *  Convenience Out function to set logger name.
     *
     * @param entry Log entry
     *
     * @return log entry in string format based on formatter
     */
    std::string Out(const LogEntry& entry) const;

public:
    /**
     * Convert severity to string. If severity is not found a LogcppException
     * will be thrown.
     *
     * @param severity Logger severity
     * @return Logger severity string representation
     */
    static std::string SeverityToString(LogSeverity severity) noexcept(false);

    /**
     * Convert string to logger severity. If severity is not found a
     * LogcppException will be thrown.
     *
     * @param severity Logger severity string representation
     * @return Logger severity
     */
    static LogSeverity StringToSeverity(const std::string& severity)
        noexcept(false);

    /**
     * Feed log entry to formatter for output.
     *
     * @param entry Log entry
     */
    static void Print(LogEntry entry);

    /**
     * Return a single logger by logger name. If logger is not found a nullptr
     * is returned. If multiple loggers share the same name, the first logger
     * found will be returned.
     *
     * @param loggerName Name of logger
     * @return Pointer to logger
     */
    static Logger::Ptr GetLogger(const std::string& loggerName);

    /**
     * Return all global loggers.
     *
     * @return List of loggers
     */
    static std::set<Logger::Ptr> GetLoggers(void);

    /**
     * Add new logger to global scope.
     *
     * @param logger Pointer to logger
     */
    static void AddLogger(Logger::Ptr logger);

    /**
     * Add new logger to global scope and return it.
     */
    template <typename T>
    static std::shared_ptr<T> MakeLogger()
    {
        std::shared_ptr<T> logger = std::make_shared<T>();
        AddLogger(logger);
        return logger;
    }

    /**
     * Remove logger from global scope by logger name.
     *
     * @param loggerName Name of logger
     */
    static void RemoveLogger(const std::string& loggerName);

protected:
    Logger(void);

    /**
     * Invoked when a message is logged by a user of this library. This method
     * handles thread synchronization and minimum logger severity.
     *
     * @param entry Log entry
     */
    virtual void ProcessLogEntry(const LogEntry& entry) = 0;

    LogSeverity m_Severity;
    std::string m_Name;
    Formatter::Ptr m_Formatter;
    std::mutex m_Mutex;

private:
    static std::mutex m_LMutex; /* Global mutex for logger list */
    static std::set<Logger::Ptr> m_Loggers; /* List of global loggers */
};

class Log
{
public:
    inline Log(LogSeverity severity, const std::string& facility,
               const std::string& message)
    : Log(severity, facility)
    {
        m_Buffer << message;
    }

    inline Log(LogSeverity severity, const std::string& facility)
    : Log(severity)
    {
        m_Entry.Facility = facility;
    }

    inline Log(LogSeverity severity)
    {
        m_Entry.Severity = severity;
    }

    inline ~Log(void)
    {
        m_Entry.Message = m_Buffer.str();
        Logger::Print(m_Entry);
    }

    Log& Context(int line, const std::string& function,
                 const std::string& file)
    {
        m_Entry.Line = line;
        m_Entry.Function = function;
        m_Entry.File = file;
        return *this;
    }

    template<typename T>
    Log& operator<<(const T& val)
    {
        m_Buffer << val;
        return *this;
    }

private:
    LogEntry m_Entry;
    std::ostringstream m_Buffer;

    Log(void);
    Log(const Log& other);
    Log& operator=(const Log& rhs);
};

};

#endif

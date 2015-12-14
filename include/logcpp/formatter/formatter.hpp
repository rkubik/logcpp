#ifndef _LOGCPP_FORMATTER_FORMATTER_HPP_
#define _LOGCPP_FORMATTER_FORMATTER_HPP_

#include <logcpp/helpers/objectptr.hpp>

namespace logcpp {

class LogEntry;

/**
 * Translate log entry into string representation. Default support for format
 * substitution:
 *
 * %t - Timestamp (based on m_DateTimeFormat)
 * %n - Logger name
 * %s - Logger severity (string representation)
 * %f - Logger facility (scope)
 * %l - Source line number (only set when using context logger)
 * %u - Source function name (only set when using context logger)
 * %i - Source filename (only set when using context logger)
 * %j - Source file basename (only set when using context logger)
 * %m - Log message
 *
 * If further formats are required (XML, JSON), simply inherit the Formatter
 * class and override the virtual ::Out method.
 */
class Formatter
{
public:
    OBJECT_PTR(Formatter);

    Formatter(const std::string& format);
    Formatter();
    virtual ~Formatter();

    /**
     * Translate log entry to string.
     *
     * @param loggerName Logger name
     * @param entry Log entry
     * @return String representation of log entry
     */
    virtual std::string Out(const std::string& loggerName,
                    const LogEntry& entry) const;

protected:
    std::string m_Format, m_DateTimeFormat;
};

};

#endif

#ifndef _LOGCPP_FORMATTER_PATTERNFORMATTER_HPP_
#define _LOGCPP_FORMATTER_PATTERNFORMATTER_HPP_

#include <logcpp/formatter/formatter.hpp>

namespace logcpp {

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
class PatternFormatter : public Formatter
{
public:
    OBJECT_PTR(PatternFormatter);

    PatternFormatter(const std::string& format,
                     const std::string& datetimeFormat);
    PatternFormatter();
    virtual ~PatternFormatter();

    void SetFormat(const std::string& format);
    void SetDateTimeFormat(const std::string& format);

    std::string GetFormat(void) const;
    std::string GetDateTimeFormat(void) const;

    std::string Out(const std::string& loggerName,
                    const LogEntry& entry) const override;

private:
    std::string m_Format, m_DateTimeFormat;
};

};

#endif

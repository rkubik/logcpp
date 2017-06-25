#include <utility.hpp>
#include <logcpp/formatter/patternformatter.hpp>
#include <logcpp/logger.hpp>
using namespace logcpp;
using namespace logcpp::helpers;

using namespace std;

PatternFormatter::PatternFormatter(
    const string& format,
    const string& datetimeFormat
)
:
m_Format(format),
m_DateTimeFormat(datetimeFormat)
{
}

PatternFormatter::PatternFormatter()
:
m_Format("[%t] %s - %m"),
m_DateTimeFormat("%Y-%m-%d %H:%M:%S")
{
}

PatternFormatter::~PatternFormatter()
{
}

void PatternFormatter::SetFormat(const string& format)
{
    m_Format = format;
}

void PatternFormatter::SetDateTimeFormat(const string& format)
{
    m_DateTimeFormat = format;
}

string PatternFormatter::GetFormat(void) const
{
    return m_Format;
}

string PatternFormatter::GetDateTimeFormat(void) const
{
    return m_DateTimeFormat;
}

string PatternFormatter::Out(const string& loggerName, const LogEntry& entry) const
{
    string output = m_Format;

    Utility::ReplaceAll(output, "%t", Utility::DateTimeFormat(entry.Timestamp, m_DateTimeFormat));
    Utility::ReplaceAll(output, "%i", to_string(entry.Milliseconds));
    Utility::ReplaceAll(output, "%n", loggerName);
    Utility::ReplaceAll(output, "%s", Logger::SeverityToString(entry.Severity));
    Utility::ReplaceAll(output, "%f", entry.Facility);
    Utility::ReplaceAll(output, "%l", entry.Line > 0 ? to_string(entry.Line) : "");
    Utility::ReplaceAll(output, "%u", entry.Function);
    Utility::ReplaceAll(output, "%i", entry.File);
    Utility::ReplaceAll(output, "%j", Utility::Basename(entry.File));
    Utility::ReplaceAll(output, "%m", entry.Message);

    return output;
}

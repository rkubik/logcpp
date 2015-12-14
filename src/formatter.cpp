#include <logcpp/formatter/formatter.hpp>
#include <logcpp/logger.hpp>
#include <logcpp/helpers/utility.hpp>
using namespace logcpp;
using namespace logcpp::helpers;

using namespace std;

Formatter::Formatter()
: m_DateTimeFormat("%Y-%m-%d %H:%M:%S")
{
}

Formatter::Formatter(const string& format)
: Formatter()
{   
    m_Format = format;
}

Formatter::~Formatter()
{
}

string Formatter::Out(const string& loggerName, const LogEntry& entry) const
{
    string output = m_Format;

    Utility::ReplaceAll(output, "%t", Utility::DateTimeFormat(entry.Timestamp, m_DateTimeFormat));
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

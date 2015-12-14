#include <logcpp/formatter/patternformatter.hpp>
using namespace logcpp;

using namespace std;

PatternFormatter::PatternFormatter() : Formatter()
{
}

PatternFormatter::PatternFormatter(const string& format)
: Formatter(format)
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
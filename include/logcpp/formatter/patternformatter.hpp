#ifndef _LOGCPP_FORMATTER_PATTERNFORMATTER_HPP_
#define _LOGCPP_FORMATTER_PATTERNFORMATTER_HPP_

#include <logcpp/formatter/formatter.hpp>

namespace logcpp {

class PatternFormatter : public Formatter
{
public:
    OBJECT_PTR(PatternFormatter);

    PatternFormatter(const std::string& format);
    PatternFormatter();
    virtual ~PatternFormatter();

    void SetFormat(const std::string& format);
    void SetDateTimeFormat(const std::string& format);

    std::string GetFormat(void) const;
    std::string GetDateTimeFormat(void) const;
};

};

#endif

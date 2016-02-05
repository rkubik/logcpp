#ifndef _LOGCPP_FORMATTER_BASICFORMATTER_HPP_
#define _LOGCPP_FORMATTER_BASICFORMATTER_HPP_

#include <logcpp/formatter/patternformatter.hpp>

namespace logcpp {

class BasicFormatter : public PatternFormatter
{
public:
    OBJECT_PTR(BasicFormatter);

    BasicFormatter();

    virtual ~BasicFormatter();
};

};

#endif

#ifndef _LOGCPP_FORMATTER_BASICFORMATTER_HPP_
#define _LOGCPP_FORMATTER_BASICFORMATTER_HPP_

#include <logcpp/formatter/formatter.hpp>

namespace logcpp {

class BasicFormatter : public Formatter
{
public:
    OBJECT_PTR(BasicFormatter);

    BasicFormatter();
};

};

#endif

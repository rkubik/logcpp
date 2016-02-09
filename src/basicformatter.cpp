#include <logcpp/formatter/basicformatter.hpp>
using namespace logcpp;

BasicFormatter::BasicFormatter() : PatternFormatter("[%t] %s - %m", "%H:%M:%S")
{
}

BasicFormatter::~BasicFormatter()
{
}

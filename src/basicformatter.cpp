#include <logcpp/formatter/basicformatter.hpp>
using namespace logcpp;

BasicFormatter::BasicFormatter() : Formatter("[%t] %s - %m")
{
}

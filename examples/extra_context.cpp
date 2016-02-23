#include <logcpp/logger.hpp>
#include <logcpp/logger/consolelogger.hpp>
#include <logcpp/formatter/patternformatter.hpp>
using namespace logcpp;

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    const bool daemon = true;

    ConsoleLogger::Ptr logger = Logger::MakeLogger<ConsoleLogger>();
    PatternFormatter::Ptr formatter = PatternFormatter::Ptr(new PatternFormatter());
    formatter->SetFormat("%t %j:%l [%s] %m");
    formatter->SetDateTimeFormat("%m-%d %H:%M:%S");
    logger->SetFormatter(formatter);
    logger->SetSeverity(LogDebug);

    Log(LogDebug) << "No context";

    LOG_DEBUG << "Context";

    return 0;
}

#include <logcpp/logger.hpp>
#include <logcpp/logger/consolelogger.hpp>
using namespace logcpp;

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    ConsoleLogger::Ptr logger = Logger::MakeLogger<ConsoleLogger>();
    logger->SetSeverity(LogDebug);

    Log(LogDebug) << "Basic setup";

    return 0;
}

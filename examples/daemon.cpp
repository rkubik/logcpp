#include <logcpp/logger.hpp>
#include <logcpp/logger/consolelogger.hpp>
#include <logcpp/logger/filelogger.hpp>
using namespace logcpp;

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    const bool daemon = true;

    Logger::Ptr logger;

    if (daemon) {
        /* daemonize */
        FileLogger::Ptr fl = Logger::MakeLogger<FileLogger>();
        fl->SetPath("test.log");
        logger = fl;
    } else {
        logger = Logger::MakeLogger<ConsoleLogger>();
    }
    logger->SetSeverity(LogDebug);

    Log(LogDebug) << "Hello";

    return 0;
}

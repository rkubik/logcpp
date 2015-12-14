#include <logcpp/logger/consolelogger.hpp>
using namespace logcpp;

#include <iostream>
using namespace std;

ConsoleLogger::ConsoleLogger() : StreamLogger(&cout, false)
{
}

ConsoleLogger::~ConsoleLogger()
{
}

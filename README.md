# logcpp

Simple Thread-Safe C++11 logging library.

## Dependencies

- C++11 compiler
- GNU/Linux platform
- cmake
- debuild (optional)

# Build

You can build and install the shared library and header with cmake or use
debuild to create Debian packages.

1. cmake

In the root of the project.

    mkdir build
    cd build
    cmake ..
    make
    make install

2. debuild

In the root of the project.

    debuild -us -uc -b -j4
    debuild clean

Which will produce both the runtime and development Debian packages.

## Usage

1. Logging to stdout:

        #include <logcpp/logger.hpp>
        #include <logcpp/logger/streamlogger.hpp>
        using namespace logcpp;

        #include <iostream>
        using namespace std;

        int main(int argc, char* argv[])
        {
            StreamLogger::Ptr logger = StreamLogger::Ptr(new StreamLogger());
            logger->SetStream(&cout, false);
            logger->SetSeverity(LogDebug);
            Logger::AddLogger(logger);

            Log(LogDebug) << "Simple Logging!";

            return 0;
        }

Output:

    [2015-08-17 09:24:56] debug: Simple Logging!

2. Specifying a custom output format:

        #include <logcpp/logger.hpp>
        #include <logcpp/logger/streamlogger.hpp>
        #include <logcpp/formatter/patternformatter.hpp>
        using namespace logcpp;

        #include <iostream>
        using namespace std;

        int main(int argc, char* argv[])
        {
            StreamLogger::Ptr logger = StreamLogger::Ptr(new StreamLogger());
            PatternFormatter::Ptr formatter = PatternFormatter::Ptr(new PatternFormatter());
            formatter->SetFormat("%t - %m");
            formatter->SetDateTimeFormat("%m-%d %H:%M:%S");
            logger->SetFormatter(formatter);
            logger->SetStream(&cout, false);
            logger->SetSeverity(LogDebug);
            Logger::AddLogger(logger);

            Log(LogDebug) << "Custom Format!";

            return 0;
        }

Output:

    08-17 09:24:27 - Custom Format!

3. Logging additional context:

        #include <logcpp/logger.hpp>
        #include <logcpp/logger/consolelogger.hpp>
        #include <logcpp/formatter/patternformatter.hpp>
        using namespace logcpp;

        int main(int argc, char* argv[])
        {
            ConsoleLogger::Ptr logger = ConsoleLogger::Ptr(new ConsoleLogger());
            PatternFormatter::Ptr formatter = PatternFormatter::Ptr(new PatternFormatter());
            formatter->SetFormat("[%t] %i:%l %s - %m");
            logger->SetFormatter(formatter);
            logger->SetSeverity(LogDebug);
            Logger::AddLogger(logger);

            LOG(LogDebug) << "More Context!";

            LOG_WARN << "Using context helpers!";

            return 0;
        }

Output:

    [2015-08-17 09:21:11] main.cpp:19 debug - More Context!
    [2015-08-17 09:21:11] main.cpp:21 warning - Using context helpers!

4. Logging to a file:

        #include <logcpp/logger.hpp>
        #include <logcpp/logger/filelogger.hpp>
        #include <logcpp/formatter/patternformatter.hpp>
        using namespace logcpp;

        int main(int argc, char* argv[])
        {
            FileLogger::Ptr logger = FileLogger::Ptr(new FileLogger());
            logger->SetPath("app.log");
            logger->SetAppend(true);
            logger->SetSeverity(LogDebug);
            Logger::AddLogger(logger);

            LOG_CRIT << "This will be in file!";

            return 0;
        }

Output:

    [2015-08-19 15:40:47] critical: This will be in file!

5. Logging to a rotating file:

        #include <logcpp/logger.hpp>
        #include <logcpp/logger/filerotatelogger.hpp>
        #include <logcpp/formatter/patternformatter.hpp>
        using namespace logcpp;

        int main(int argc, char* argv[])
        {
            FileRotateLogger::Ptr logger = FileRotateLogger::Ptr(new FileRotateLogger());
            logger->SetPath("app.log");
            logger->SetMaxBackup(2);
            logger->SetMaxSize(10); /* Bytes */
            logger->SetAppend(true);
            logger->SetSeverity(LogDebug);
            Logger::AddLogger(logger);

            LOG_CRIT << "This will be in app.log.1";
            LOG_CRIT << "This will be in app.log.2";

            return 0;
        }

Output:

    [2015-08-19 15:40:47] critical: This will be in app.log.1
    [2015-08-19 15:40:47] critical: This will be in app.log.2

## TODO

- Unit tests
- Documentation (doxygen)
- FileRotateLogger add compression

## License

MIT

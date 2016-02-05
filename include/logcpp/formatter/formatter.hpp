#ifndef _LOGCPP_FORMATTER_FORMATTER_HPP_
#define _LOGCPP_FORMATTER_FORMATTER_HPP_

#include <logcpp/helpers/objectptr.hpp>

namespace logcpp {

class LogEntry;


class Formatter
{
public:
    OBJECT_PTR(Formatter);

    virtual ~Formatter() {}

    /**
     * Translate log entry to string.
     *
     * @param loggerName Logger name
     * @param entry Log entry
     * @return String representation of log entry
     */
    virtual std::string Out(const std::string& loggerName,
                            const LogEntry& entry) const = 0;
protected:
    Formatter() {}
};

};

#endif

#ifndef _LOGCPP_LOGGER_STREAMLOGGER_HPP_
#define _LOGCPP_LOGGER_STREAMLOGGER_HPP_

#include <logcpp/logger.hpp>

#include <ostream>

namespace logcpp {

class StreamLogger : public Logger
{
public:
    OBJECT_PTR(StreamLogger);

    StreamLogger(std::ostream* stream, bool ownsStream);
    StreamLogger();
    virtual ~StreamLogger();

    /**
     * Return pointer to current stream.
     *
     * @return Pointer to stream
     */
    std::ostream* GetStream(void) const;

    /**
     * Set stream.
     *
     * @param stream Stream to set
     * @param ownsStream Whether or not logger should handle stream lifecycle
     */
    void SetStream(std::ostream* stream, bool ownsStream);

    /**
     * Flush stream.
     */
    void Flush(void);

protected:
    void ProcessLogEntry(const LogEntry& entry) override;

private:
    std::ostream *m_Stream;
    bool m_OwnsStream;
};

};

#endif

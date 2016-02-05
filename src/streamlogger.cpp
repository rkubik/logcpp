#include <logcpp/logger/streamlogger.hpp>
#include <logcpp/helpers/utility.hpp>
using namespace logcpp;

using namespace std;

StreamLogger::StreamLogger() : StreamLogger(nullptr, false)
{
}

StreamLogger::StreamLogger(ostream* stream, bool ownsStream)
: m_Stream(stream), m_OwnsStream(ownsStream)
{
}

StreamLogger::~StreamLogger()
{
    if (m_Stream) {
        Flush();
    }

    if (m_Stream && m_OwnsStream) {
        delete m_Stream;
    }
}

void StreamLogger::SetStream(ostream* stream, bool ownsStream)
{
    if (m_Stream && m_OwnsStream) {
        delete m_Stream;
    }

    m_Stream = stream;
    m_OwnsStream = ownsStream;
}

ostream* StreamLogger::GetStream(void) const
{
    return m_Stream;
}

void StreamLogger::Flush(void)
{
    if (m_Stream) {
        m_Stream->flush();
    }
}

void StreamLogger::ProcessLogEntry(const LogEntry& entry)
{
    if (m_Stream) {
        *m_Stream << Out(entry) << endl;
    }

    Flush();
}

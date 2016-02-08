#include <logcpp/logger/filelogger.hpp>
#include <logcpp/helpers/exception.hpp>
using namespace logcpp;
using namespace logcpp::helpers;

#include <fstream>
using namespace std;

FileLogger::FileLogger(const string& path) : FileLogger()
{
    SetPath(path);
}

FileLogger::FileLogger() : m_Append(false)
{
}

FileLogger::~FileLogger()
{
}

void FileLogger::SetAppend(bool append)
{
    m_Append = append;
}

bool FileLogger::GetAppend(void) const
{
    return m_Append;
}

void FileLogger::SetPath(const string& path)
{
    m_Path = path;
}

string FileLogger::GetPath(void) const
{
    return m_Path;
}

size_t FileLogger::GetFileSize(void)
{
    ifstream stream;

    stream.open(GetPath(), fstream::binary);

    if (!stream.good()) {
        return 0;
    }

    stream.seekg(0, fstream::end);

    return stream.tellg();
}

void FileLogger::ReopenLogFile(void)
{
    ofstream *stream = new ofstream();

    try {
        stream->open(GetPath(), m_Append ? fstream::app : fstream::trunc |
            fstream::out);

        if (!stream->good()) {
            throw LogcppException("Could not open logfile '" + GetPath() + "'");
        }
    } catch (const exception &e) {
        delete stream;
        throw LogcppException(e.what());
    }

    SetStream(stream, true);
}

void FileLogger::CloseLogFile(void)
{
    SetStream(nullptr, false);
}

void FileLogger::ProcessLogEntry(const LogEntry& entry)
{
    if (!GetStream()) {
        ReopenLogFile();
    }

    StreamLogger::ProcessLogEntry(entry);
}

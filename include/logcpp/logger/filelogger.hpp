#ifndef _LOGCPP_LOGGER_FILELOGGER_HPP_
#define _LOGCPP_LOGGER_FILELOGGER_HPP_

#include <logcpp/logger/streamlogger.hpp>

namespace logcpp {

class FileLogger : public StreamLogger
{
public:
    OBJECT_PTR(FileLogger);

    FileLogger();
    FileLogger(const std::string& path);
    virtual ~FileLogger();

    /**
     * Set log appending option.
     *
     * @param append Append to log file
     */
    void SetAppend(bool append);

    /**
     * Set log path.
     *
     * @param path Log filename
     */
    void SetPath(const std::string& path);

    /**
     * Return append option.
     *
     * @return Log appending on/off
     */
    bool GetAppend(void) const;

    /**
     * Return filename of log file.
     *
     * @return Log filename
     */
    std::string GetPath(void) const;

    /**
     * Return log file  size in bytes.
     *
     * @return Filesize (bytes)
     */
    size_t GetFileSize(void);

protected:
    void ProcessLogEntry(const LogEntry& entry) override;

    /**
     * Close and open log file. If the file cannot be opened for any reason a
     * LogcppException will be thrown.
     */
    void ReopenLogFile(void) noexcept(false);

    /**
     * Close log file.
     */
    void CloseLogFile(void);

private:
    std::string m_Path;
    bool m_Append;
};

};

#endif

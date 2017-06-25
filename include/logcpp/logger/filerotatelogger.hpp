#ifndef _LOGCPP_LOGGER_FILEROTATELOGGER_HPP_
#define _LOGCPP_LOGGER_FILEROTATELOGGER_HPP_

#include <logcpp/logger/filelogger.hpp>

namespace logcpp {

class FileRotateLogger : public FileLogger
{
public:
    OBJECT_PTR(FileRotateLogger);

    FileRotateLogger();
    FileRotateLogger(const std::string& path);

    /**
     * Set maximum number backups option.
     *
     * @param rotate Maximum number backups
     */
    void SetMaxBackup(size_t rotate);

    /**
     * Set maximum file size option.
     *
     * @param size Maximum file size (bytes)
     */
    void SetMaxSize(size_t size);

    /**
     * Return maximum number of log backups.
     *
     * @return Maximum file backups
     */
    size_t GetMaxBackup(void) const;

    /**
     * Return maximum file size option.
     *
     * @return Maximum file size (bytes)
     */
    size_t GetMaxSize(void) const;

protected:
    void ProcessLogEntry(const LogEntry& entry) override;

private:
    const static char BACKUP_DELIMETER;
    const static size_t DEFAULT_MAX_BACKUP;
    const static size_t DEFAULT_MAX_SIZE;

    /**
     * Return backup filename based on the backup index.
     */
    virtual std::string BackupName(size_t idx);

    /**
     * Rotate log file based on maximum number of backups and maximum file size.
     * Backup files are named <filename><delimiter><backup-number>.
     *
     * Example:
     *
     * logger->SetPath('/tmp/main.log');
     * logger->SetMaxSize(1);
     * logger->SetMaxBackup(5);
     * LOG << "Testing";
     *
     * $ ls -lah /tmp/main.log*
     * /tmp/main.log
     * /tmp/main.log.1
     * /tmp/main.log.2
     * /tmp/main.log.3
     * /tmp/main.log.4
     * /tmp/main.log.5
     */
    void RotateLogFile(void);

    size_t m_Backup, m_Size;
};

};

#endif

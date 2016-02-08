#include <logcpp/logger/filerotatelogger.hpp>
#include <logcpp/helpers/exception.hpp>
#include <logcpp/helpers/utility.hpp>
using namespace logcpp;
using namespace logcpp::helpers;

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

const char FileRotateLogger::BACKUP_DELIMETER = '.';

FileRotateLogger::FileRotateLogger(const string& path)
: FileLogger(path)
{
    FileRotateLogger();
}

FileRotateLogger::FileRotateLogger()
:
m_Backup(1),
m_Size(10000000)
{
}

size_t FileRotateLogger::GetMaxBackup(void) const
{
    return m_Backup;
}

size_t FileRotateLogger::GetMaxSize(void) const
{
    return m_Size;
}

void FileRotateLogger::SetMaxBackup(size_t backup)
{
    m_Backup = backup;
}

void FileRotateLogger::SetMaxSize(size_t size)
{
    m_Size = size;
}

string FileRotateLogger::BackupName(size_t idx)
{
    ostringstream os;
    os << GetPath() << BACKUP_DELIMETER << idx;
    return os.str();
}

void FileRotateLogger::RotateLogFile(void)
{
    if (GetFileSize() < GetMaxSize()) {
        return;
    }

    vector<string> logFiles = Utility::FileGlob(GetPath() + BACKUP_DELIMETER +
        "*");
    size_t logFileId = logFiles.size() + 1;

    if (logFileId >= GetMaxBackup()) {
        size_t idx = 1;
        for (size_t i = 0; i < logFiles.size(); ++i) {
            if (logFiles.size() - i >= GetMaxBackup()) {
                remove(logFiles[i].c_str());
            } else {
                rename(logFiles[i].c_str(), BackupName(idx++).c_str());
            }
        }
        logFileId = idx;
    }

    if (GetMaxBackup() > 0) {
        CloseLogFile();

        rename(GetPath().c_str(), BackupName(logFileId).c_str());
    }
}

void FileRotateLogger::ProcessLogEntry(const LogEntry& entry)
{
    FileLogger::ProcessLogEntry(entry);

    RotateLogFile();
}

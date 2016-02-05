#include <logcpp/helpers/utility.hpp>
using namespace logcpp;
using namespace logcpp::helpers;

#include <ctime>
#include <cmath>
#include <chrono>
using namespace std::chrono;
using namespace std;

#include <glob.h>

double Utility::GetTime()
{
    return chrono::duration_cast<chrono::duration<double>>
        (chrono::system_clock::now().time_since_epoch()).count();
}

string Utility::DateTimeFormat(double timestamp, const string& format)
{
    const static size_t datetime_bufsiz = 80;

    char buffer[datetime_bufsiz];
    time_t time = timestamp;
    tm *timeinfo = localtime(&time);

    strftime(buffer, datetime_bufsiz, format.c_str(), timeinfo);

    return buffer;
}

void Utility::ReplaceAll(string &str, const string& from,
                       const string& to)
{
    if(from.empty())
        return;

    size_t start_pos = 0;

    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

vector<string> Utility::FileGlob(const string& pattern)
{
    vector<string> results;
    glob_t glob_result;

    glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);

    for(size_t i = 0; i < glob_result.gl_pathc; ++i) {
        results.push_back(glob_result.gl_pathv[i]);
    }

    globfree(&glob_result);

    return results;
}

string  Utility::Basename(const string &path)
{
    return path.substr(path.find_last_of("/\\") + 1);
}

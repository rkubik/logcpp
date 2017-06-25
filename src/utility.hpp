#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_

#include <string>
#include <vector>

namespace logcpp {

namespace helpers {

class Utility {
public:
    /**
     * Return a Unix timestamp of current datetime.
     *
     * @return Unix timestamp in milliseconds
     */
    static double GetTime();

    /**
     * Format timestamp into datetime string.
     *
     * @param timestamp Unix timestamp
     * @param format Format of datetime
     *
     * @return Datetime in given format
     */
    static std::string DateTimeFormat(double timestamp, 
                                      const std::string& format);

    /**
     * Replace all occurances of given string.
     *
     * @param str Reference to search string
     * @param from String to replace
     * @param to String to substitute
     */
    static void ReplaceAll(std::string& str, 
                           const std::string& from,
                           const std::string& to);

    /**
     * Return a list of filenames from a given glob pattern.
     *
     * @param pattern Glob pattern
     *
     * @return List of filenames
     */
    static std::vector<std::string> FileGlob(const std::string& pattern);

    /**
     * Return the basename of a filename/filepath.
     *
     * @param path Filename or path
     *
     * @return Basename
     */
    static std::string Basename(const std::string &path);
};

};

};

#endif

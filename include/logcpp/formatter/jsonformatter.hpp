#ifndef _LOGCPP_FORMATTER_JSONFORMATTER_HPP_
#define _LOGCPP_FORMATTER_JSONFORMATTER_HPP_

#include <logcpp/formatter/formatter.hpp>

#include <vector>

namespace logcpp {

class JsonFormatter : public Formatter
{
public:
    OBJECT_PTR(JsonFormatter);

    JsonFormatter();
    JsonFormatter(std::vector<std::string> attributes);
    virtual ~JsonFormatter();

    std::string Out(const std::string& loggerName, 
                    const LogEntry& entry) const override;

    /**
     * Escape all double quotes and return string wrapped in double quotes.
     * 
     * Example:
     * 
     * `error: "something wrong"` => "error: \"something wrong\""
     * 
     * @param str String to JSON format
     * 
     * @return escaped string with double quotes
     */
    static std::string Wrap(std::string str);

private:
    std::vector<std::string> m_Attributes;
};

};

#endif

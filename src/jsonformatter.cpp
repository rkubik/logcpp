#include <logcpp/formatter/jsonformatter.hpp>
#include <logcpp/logger.hpp>
#include <logcpp/helpers/utility.hpp>
using namespace logcpp;
using namespace logcpp::helpers;

#include <utility>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

JsonFormatter::JsonFormatter(vector<string> attributes) 
: m_Attributes(attributes)
{
}

JsonFormatter::JsonFormatter()
{
}

JsonFormatter::~JsonFormatter()
{
}

string JsonFormatter::Out(const string& loggerName, const LogEntry& entry) const
{
    ostringstream ss;
    map<string, pair<string, bool>> attr = {
        {"timestamp", {Utility::DateTimeFormat(entry.Timestamp, "%Y-%m-%d %H:%M:%S"), false}},
        {"logger",    {loggerName, false}},
        {"severity",  {Logger::SeverityToString(entry.Severity), false}},
        {"facility",  {entry.Facility, false}},
        {"message",   {entry.Message, false}},
        {"line",      {to_string(entry.Line), true}},
        {"function",  {entry.Function, false}},
        {"file",      {Utility::Basename(entry.File), false}}
    };
    
    map<string, pair<string, bool>>::iterator iter;

    for (iter = attr.begin(); iter != attr.end(); ++iter) {
        if (m_Attributes.empty() || std::any_of(m_Attributes.cbegin(), 
                                                m_Attributes.cend(), 
            [iter](const string &attribute) {
                return attribute == (*iter).first;
            }))
        {
            if (!ss.str().empty()) {
                ss << ",";
            }

            ss << JsonFormatter::Wrap((*iter).first)
               << ":"
               << ((*iter).second.second ? 
                      (*iter).second.first : 
                      JsonFormatter::Wrap((*iter).second.first));
        }
    }

    return "{" + ss.str() + "}";
}

std::string JsonFormatter::Wrap(std::string str)
{
    Utility::ReplaceAll(str, "\"", "\\\"\"");
    return  "\"" + str + "\"";
}

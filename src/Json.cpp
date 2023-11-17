#include "Json.hpp"

using namespace jsoncpp;

ijson::Error::Error(const std::string &message):
    _msg()
{
}

const char *ijson::Error::what() const noexcept {
    return _msg.c_str();
}

std::ostream &operator<<(std::ostream &os, const jsoncpp::ijson &json)
{
    return os << json.toString();
}

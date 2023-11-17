#include "Json.hpp"

using namespace jsoncpp;

ijson::Error::Error(const std::string &message):
    _msg()
{
}

const char *ijson::Error::what() const noexcept {
    return _msg.c_str();
}


jsonptr::jsonptr():
    _value(nullptr)
{
}

jsonptr::jsonptr(jsonptr &&other)
{
    _value = std::move(other._value);
}

jsonptr::jsonptr(std::unique_ptr<ijson> &&value):
    _value(std::move(value))
{
}

jsonptr &jsonptr::operator=(jsonptr &&other)
{
    _value = std::move(other._value);
    return *this;
}

jsonptr &jsonptr::operator=(std::unique_ptr<ijson> &&value)
{
    _value = std::move(value);
    return *this;
}


std::ostream &operator<<(std::ostream &os, const jsoncpp::ijson &json)
{
    return os << json.toString();
}

std::ostream &operator<<(std::ostream &os, const jsoncpp::jsonptr &json)
{
    return os << json.toString();
}

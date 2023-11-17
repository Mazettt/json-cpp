#include "String.hpp"

using namespace jsoncpp;

String::String()
{
}

String::String(const JSON_STRING &value):
    _value(value)
{
}

String::String(const String &other)
{
    _value = other._value;
}

String::String(String &&other)
{
    _value = std::move(other._value);
}

String &String::operator=(const String &other)
{
    _value = other._value;
    return *this;
}

String &String::operator=(String &&other)
{
    _value = std::move(other._value);
    return *this;
}

std::string String::toString(int indent) const
{
    return "\"" + _value + "\"";
}

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

ijson &String::operator=(const ijson &other)
{
    try {
        const String &otherString = dynamic_cast<const String &>(other);
        _value = otherString._value;
    } catch (const std::bad_cast &e) {
        throw std::runtime_error("Cannot assign a non-string value to a string");
    }
    return *this;
}

ijson &String::operator=(ijson &&other)
{
    try {
        String &otherString = dynamic_cast<String &>(other);
        _value = std::move(otherString._value);
    } catch (const std::bad_cast &e) {
        throw std::runtime_error("Cannot assign a non-string value to a string");
    }
    return *this;
}

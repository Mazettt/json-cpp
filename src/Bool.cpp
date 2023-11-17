#include "Bool.hpp"

using namespace jsoncpp;

Bool::Bool():
    _value(false)
{
}

Bool::Bool(JSON_BOOL value):
    _value(value)
{
}

Bool::Bool(const Bool &other)
{
    _value = other._value;
}

Bool::Bool(Bool &&other)
{
    _value = std::move(other._value);
}

Bool &Bool::operator=(const Bool &other)
{
    _value = other._value;
    return *this;
}

Bool &Bool::operator=(Bool &&other)
{
    _value = std::move(other._value);
    return *this;
}

std::string Bool::toString(int indent) const
{
    return _value ? "true" : "false";
}

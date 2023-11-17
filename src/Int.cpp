#include "Int.hpp"

using namespace jsoncpp;

Int::Int():
    _value(0)
{
}

Int::Int(JSON_INT value):
    _value(value)
{
}

Int::Int(const Int &other)
{
    _value = other._value;
}

Int::Int(Int &&other)
{
    _value = std::move(other._value);
}

Int &Int::operator=(const Int &other)
{
    _value = other._value;
    return *this;
}

Int &Int::operator=(Int &&other)
{
    _value = std::move(other._value);
    return *this;
}

std::string Int::toString(int indent) const
{
    return std::to_string(_value);
}

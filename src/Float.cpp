#include "Float.hpp"

using namespace jsoncpp;

Float::Float():
    _value(0.0f)
{
}

Float::Float(JSON_FLOAT value):
    _value(value)
{
}

Float::Float(const Float &other)
{
    _value = other._value;
}

Float::Float(Float &&other)
{
    _value = std::move(other._value);
}

Float &Float::operator=(const Float &other)
{
    _value = other._value;
    return *this;
}

Float &Float::operator=(Float &&other)
{
    _value = std::move(other._value);
    return *this;
}

std::string Float::toString(int indent) const
{
    return std::to_string(_value);
}

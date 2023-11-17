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

ijson &Float::operator=(const ijson &other)
{
    try {
        const Float &otherFloat = dynamic_cast<const Float &>(other);
        _value = otherFloat._value;
    } catch (const std::bad_cast &e) {
        throw std::runtime_error("Cannot assign a non-float value to a float");
    }
    return *this;
}

ijson &Float::operator=(ijson &&other)
{
    try {
        Float &otherFloat = dynamic_cast<Float &>(other);
        _value = std::move(otherFloat._value);
    } catch (const std::bad_cast &e) {
        throw std::runtime_error("Cannot assign a non-float value to a float");
    }
    return *this;
}

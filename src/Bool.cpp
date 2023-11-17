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

ijson &Bool::operator=(const ijson &other)
{
    try {
        const Bool &otherBool = dynamic_cast<const Bool &>(other);
        _value = otherBool._value;
    } catch (const std::bad_cast &e) {
        throw std::runtime_error("Cannot assign a non-bool value to a bool");
    }
    return *this;
}

ijson &Bool::operator=(ijson &&other)
{
    try {
        Bool &otherBool = dynamic_cast<Bool &>(other);
        _value = std::move(otherBool._value);
    } catch (const std::bad_cast &e) {
        throw std::runtime_error("Cannot assign a non-bool value to a bool");
    }
    return *this;
}

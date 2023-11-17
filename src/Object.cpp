#include "Object.hpp"

using namespace jsoncpp;

Object::Object()
{
}

Object::Object(const JSON_OBJECT &value):
    _value(value)
{
}

Object::Object(const Object &other)
{
    _value = other._value;
}

Object::Object(Object &&other)
{
    _value = std::move(other._value);
}

Object &Object::operator=(const Object &other)
{
    _value = other._value;
    return *this;
}

Object &Object::operator=(Object &&other)
{
    _value = std::move(other._value);
    return *this;
}

std::string Object::toString(int indent) const
{
    std::string result = "{";
    for (auto &value : _value) {
        result += value.first + ": " + value.second->toString(indent) + ", ";
    }
    result += "}";
    return result;
}

ijson &Object::operator=(const ijson &other)
{
    try {
        const Object &otherObject = dynamic_cast<const Object &>(other);
        _value = otherObject._value;
    } catch (const std::bad_cast &e) {
        throw std::runtime_error("Cannot assign a non-object value to an object");
    }
    return *this;
}

ijson &Object::operator=(ijson &&other)
{
    try {
        Object &otherObject = dynamic_cast<Object &>(other);
        _value = std::move(otherObject._value);
    } catch (const std::bad_cast &e) {
        throw std::runtime_error("Cannot assign a non-object value to an object");
    }
    return *this;
}

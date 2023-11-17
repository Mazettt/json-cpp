#include "Object.hpp"

using namespace jsoncpp;

Object::Object()
{
}

Object::Object(JSON_OBJECT &&value):
    _value(std::move(value))
{
}

Object::Object(Object &&other)
{
    _value = std::move(other._value);
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
        result += value.first + ": " + value.second.toString(indent) + ", ";
    }
    result += "}";
    return result;
}

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

std::string Object::toString(int indent, int __baseIndent) const
{
    std::string result = "{";
    for (auto it = _value.begin(); it != _value.end(); ++it) {
        if (it != _value.begin())
            result += ",";
        if (indent > 0) {
            result += "\n";
            result += std::string(indent, ' ');
        }
        result += "\"" + it->first + "\":" + (indent > 0 ? " " : "");
        result += it->second.toString(indent + __baseIndent, __baseIndent);
    }
    if (indent > 0) {
        result += "\n";
        result += std::string(indent - __baseIndent, ' ');
    }
    result += "}";
    return result;
}

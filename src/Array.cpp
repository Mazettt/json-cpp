#include "Array.hpp"

using namespace jsoncpp;

Array::Array()
{
}

Array::Array(JSON_ARRAY &&value):
    _value(std::move(value))
{
}

Array::Array(Array &&other)
{
    _value = std::move(other._value);
}

Array &Array::operator=(Array &&other)
{
    _value = std::move(other._value);
    return *this;
}

std::string Array::toString(int indent, int __baseIndent) const
{
    std::string result = "[";
    for (auto it = _value.begin(); it != _value.end(); ++it) {
        if (it != _value.begin())
            result += ",";
        if (indent > 0) {
            result += "\n";
            result += std::string(indent, ' ');
        }
        result += it->toString(indent + __baseIndent, __baseIndent);
    }
    if (indent > 0) {
        result += "\n";
        result += std::string(indent - __baseIndent, ' ');
    }
    result += "]";
    return result;
}

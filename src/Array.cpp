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

std::string Array::toString(int indent) const
{
    // std::string result = "[";
    // if (indent >= 0)
    //     result += "\n";
    // for (int i = 0; i < _value.size(); i++)
    // {
    //     if (indent >= 0)
    //         result += std::string(indent + 1, ' ');
    //     result += _value[i]->toString(indent >= 0 ? indent + 1 : -1);
    //     if (i != _value.size() - 1)
    //         result += ",";
    //     if (indent >= 0)
    //         result += "\n";
    // }
    // if (indent >= 0)
    //     result += std::string(indent, ' ');
    // result += "]";
    // return result;
    std::string result = "[";
    for (auto &value : _value)
    {
        result += value->toString(indent);
        result += ",";
    }
    result += "]";
    return result;
}

ijson &Array::operator=(const ijson &other)
{
    throw std::runtime_error("Cannot copy an array");
}

ijson &Array::operator=(ijson &&other)
{
    try {
        Array &otherArray = dynamic_cast<Array &>(other);
        _value = std::move(otherArray._value);
    } catch (const std::bad_cast &e) {
        throw std::runtime_error("Cannot assign a non-array value to an array");
    }
    return *this;
}
#include "Json.hpp"
#include "Array.hpp"
#include "Object.hpp"
#include "Bool.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "String.hpp"
#include "Null.hpp"

using namespace jsoncpp;

ijson::Error::Error(const std::string &message):
    _msg()
{
}

const char *ijson::Error::what() const noexcept {
    return _msg.c_str();
}


jsonptr::jsonptr():
    _value(std::make_unique<Null>())
{}

jsonptr::jsonptr(jsonptr &&other):
    _value(std::move(other._value))
{}

jsonptr::jsonptr(std::unique_ptr<ijson> &&value):
    _value(std::move(value))
{}

jsonptr::jsonptr(Array &&value):
    _value(std::make_unique<Array>(std::move(value)))
{}

jsonptr::jsonptr(Object &&value):
    _value(std::make_unique<Object>(std::move(value)))
{}

jsonptr::jsonptr(Bool &&value):
    _value(std::make_unique<Bool>(std::move(value)))
{}

jsonptr::jsonptr(Float &&value):
    _value(std::make_unique<Float>(std::move(value)))
{}

jsonptr::jsonptr(Int &&value):
    _value(std::make_unique<Int>(std::move(value)))
{}

jsonptr::jsonptr(String &&value):
    _value(std::make_unique<String>(std::move(value)))
{}

jsonptr::jsonptr(JSON_ARRAY &&value):
    _value(std::make_unique<Array>(std::move(value)))
{}

jsonptr::jsonptr(JSON_OBJECT &&value):
    _value(std::make_unique<Object>(std::move(value)))
{}

jsonptr::jsonptr(JSON_BOOL value):
    _value(std::make_unique<Bool>(value))
{}

jsonptr::jsonptr(JSON_FLOAT value):
    _value(std::make_unique<Float>(value))
{}

jsonptr::jsonptr(JSON_INT value):
    _value(std::make_unique<Int>(value))
{}

jsonptr::jsonptr(JSON_STRING value):
    _value(std::make_unique<String>(value))
{}

jsonptr::jsonptr(const char *value):
    _value(value == nullptr ? static_cast<std::unique_ptr<ijson>>(std::make_unique<Null>()) : std::make_unique<String>(value))
{}

jsonptr &jsonptr::operator=(jsonptr &&other)
{
    _value = std::move(other._value);
    return *this;
}

jsonptr &jsonptr::operator=(std::unique_ptr<ijson> &&value)
{
    _value = std::move(value);
    return *this;
}

jsonptr &jsonptr::operator=(Array &&value)
{
    _value = std::make_unique<Array>(std::move(value));
    return *this;
}

jsonptr &jsonptr::operator=(Object &&value)
{
    _value = std::make_unique<Object>(std::move(value));
    return *this;
}

jsonptr &jsonptr::operator=(Bool &&value)
{
    _value = std::make_unique<Bool>(std::move(value));
    return *this;
}

jsonptr &jsonptr::operator=(Float &&value)
{
    _value = std::make_unique<Float>(std::move(value));
    return *this;
}

jsonptr &jsonptr::operator=(Int &&value)
{
    _value = std::make_unique<Int>(std::move(value));
    return *this;
}

jsonptr &jsonptr::operator=(String &&value)
{
    _value = std::make_unique<String>(std::move(value));
    return *this;
}

jsonptr &jsonptr::operator=(JSON_ARRAY &&value)
{
    _value = std::make_unique<Array>(std::move(value));
    return *this;
}

jsonptr &jsonptr::operator=(JSON_OBJECT &&value)
{
    _value = std::make_unique<Object>(std::move(value));
    return *this;
}

jsonptr &jsonptr::operator=(JSON_BOOL value)
{
    _value = std::make_unique<Bool>(value);
    return *this;
}

jsonptr &jsonptr::operator=(JSON_FLOAT value)
{
    _value = std::make_unique<Float>(value);
    return *this;
}

jsonptr &jsonptr::operator=(JSON_INT value)
{
    _value = std::make_unique<Int>(value);
    return *this;
}

jsonptr &jsonptr::operator=(JSON_STRING value)
{
    _value = std::make_unique<String>(value);
    return *this;
}

jsonptr &jsonptr::operator=(const char *value)
{
    if (value == nullptr)
        _value = std::make_unique<Null>();
    else
        _value = std::make_unique<String>(value);
    return *this;
}

std::string jsonptr::toString(int indent, int __baseIndent) const
{
    if (indent > 0 && __baseIndent == 0)
        __baseIndent = indent;
    return _value->toString(indent, __baseIndent);
}


std::ostream &operator<<(std::ostream &os, const jsoncpp::ijson &json)
{
    return os << json.toString();
}

std::ostream &operator<<(std::ostream &os, const jsoncpp::jsonptr &json)
{
    return os << json.toString();
}

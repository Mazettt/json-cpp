#include "Json.hpp"
#include "types/Array.hpp"
#include "types/Object.hpp"
#include "types/Bool.hpp"
#include "types/Float.hpp"
#include "types/Int.hpp"
#include "types/String.hpp"
#include "types/Null.hpp"
#include "Parser.hpp"

using namespace jsoncpp;

ijson::Error::Error(const std::string &message):
    _msg()
{
}

const char *ijson::Error::what() const noexcept {
    return _msg.c_str();
}


json::json():
    _value(std::make_unique<Null>())
{}

json::json(json &&other):
    _value(std::move(other._value))
{}

json::json(std::unique_ptr<ijson> &&value):
    _value(std::move(value))
{}

json::json(Array &&value):
    _value(std::make_unique<Array>(std::move(value)))
{}

json::json(Object &&value):
    _value(std::make_unique<Object>(std::move(value)))
{}

json::json(Bool &&value):
    _value(std::make_unique<Bool>(std::move(value)))
{}

json::json(Float &&value):
    _value(std::make_unique<Float>(std::move(value)))
{}

json::json(Int &&value):
    _value(std::make_unique<Int>(std::move(value)))
{}

json::json(String &&value):
    _value(std::make_unique<String>(std::move(value)))
{}

json::json(JSON_ARRAY &&value):
    _value(std::make_unique<Array>(std::move(value)))
{}

json::json(JSON_OBJECT &&value):
    _value(std::make_unique<Object>(std::move(value)))
{}

json::json(JSON_BOOL value):
    _value(std::make_unique<Bool>(value))
{}

json::json(JSON_FLOAT value):
    _value(std::make_unique<Float>(value))
{}

json::json(JSON_INT value):
    _value(std::make_unique<Int>(value))
{}

json::json(JSON_STRING value):
    _value(std::make_unique<String>(value))
{}

json::json(const char *value):
    _value(value == nullptr ? static_cast<std::unique_ptr<ijson>>(std::make_unique<Null>()) : std::make_unique<String>(value))
{}

json &json::operator=(json &&other)
{
    _value = std::move(other._value);
    return *this;
}

json &json::operator=(std::unique_ptr<ijson> &&value)
{
    _value = std::move(value);
    return *this;
}

json &json::operator=(Array &&value)
{
    _value = std::make_unique<Array>(std::move(value));
    return *this;
}

json &json::operator=(Object &&value)
{
    _value = std::make_unique<Object>(std::move(value));
    return *this;
}

json &json::operator=(Bool &&value)
{
    _value = std::make_unique<Bool>(std::move(value));
    return *this;
}

json &json::operator=(Float &&value)
{
    _value = std::make_unique<Float>(std::move(value));
    return *this;
}

json &json::operator=(Int &&value)
{
    _value = std::make_unique<Int>(std::move(value));
    return *this;
}

json &json::operator=(String &&value)
{
    _value = std::make_unique<String>(std::move(value));
    return *this;
}

json &json::operator=(JSON_ARRAY &&value)
{
    _value = std::make_unique<Array>(std::move(value));
    return *this;
}

json &json::operator=(JSON_OBJECT &&value)
{
    _value = std::make_unique<Object>(std::move(value));
    return *this;
}

json &json::operator=(JSON_BOOL value)
{
    _value = std::make_unique<Bool>(value);
    return *this;
}

json &json::operator=(JSON_FLOAT value)
{
    _value = std::make_unique<Float>(value);
    return *this;
}

json &json::operator=(JSON_INT value)
{
    _value = std::make_unique<Int>(value);
    return *this;
}

json &json::operator=(JSON_STRING value)
{
    _value = std::make_unique<String>(value);
    return *this;
}

json &json::operator=(const char *value)
{
    if (value == nullptr)
        _value = std::make_unique<Null>();
    else
        _value = std::make_unique<String>(value);
    return *this;
}

std::string json::toString(int indent, int __baseIndent) const
{
    if (indent > 0 && __baseIndent == 0)
        __baseIndent = indent;
    return _value->toString(indent, __baseIndent);
}

json::operator Array &()
{
    return dynamic_cast<Array &>(*this->_value);
}

json::operator Object &()
{
    return dynamic_cast<Object &>(*this->_value);
}

json::operator Bool &()
{
    return dynamic_cast<Bool &>(*this->_value);
}

json::operator Float &()
{
    return dynamic_cast<Float &>(*this->_value);
}

json::operator Int &()
{
    return dynamic_cast<Int &>(*this->_value);
}

json::operator String &()
{
    return dynamic_cast<String &>(*this->_value);
}

json::operator Null &()
{
    return dynamic_cast<Null &>(*this->_value);
}

json json::parse(const std::string &jsonStr)
{
    Parser parser(jsonStr);
    return parser.parse();
}

json json::parse(std::ifstream &is)
{
    Parser parser(is);
    return parser.parse();
}


std::ostream &operator<<(std::ostream &os, const jsoncpp::ijson &j)
{
    return os << j.toString();
}

std::ostream &operator<<(std::ostream &os, const jsoncpp::json &j)
{
    return os << j.toString();
}

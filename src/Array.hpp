#pragma once

#include <memory>
#include "Json.hpp"

namespace jsoncpp
{
    class Array : public ijson
    {
    public:
        Array();
        Array(const JSON_ARRAY &value) = delete;
        Array(JSON_ARRAY &&value);
        Array(const Array &other) = delete;
        Array(Array &&other);
        Array &operator=(const Array &other) = delete;
        Array &operator=(Array &&other);
        virtual ~Array() = default;

        virtual std::string toString(int indent = -1) const override;

        virtual const ijson &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use string as array index"); }
        virtual const ijson &operator[](const char *key) const override { throw std::runtime_error("Cannot use string as array index"); }
        virtual const ijson &operator[](size_t index) const override { return *_value[index]; }

        virtual ijson &operator[](const std::string &key) override { throw std::runtime_error("Cannot use string as array index"); }
        virtual ijson &operator[](const char *key) override { throw std::runtime_error("Cannot use string as array index"); }
        virtual ijson &operator[](size_t index) override { return *_value[index]; }

        virtual ijson &operator=(const ijson &other) override;
        virtual ijson &operator=(ijson &&other) override;

        virtual const JSON_ARRAY &getArray() const override { return _value; }
        virtual const JSON_OBJECT &getObject() const override { throw std::runtime_error("Cannot convert array to object"); }
        virtual JSON_FLOAT getFloat() const override { throw std::runtime_error("Cannot convert array to float"); }
        virtual JSON_INT getInt() const override { throw std::runtime_error("Cannot convert array to int"); }
        virtual JSON_STRING getString() const override { throw std::runtime_error("Cannot convert array to string"); }
        virtual JSON_BOOL getBool() const override { throw std::runtime_error("Cannot convert array to bool"); }

        virtual JSON_ARRAY &getArray() override { return _value; }
        virtual JSON_OBJECT &getObject() override { throw std::runtime_error("Cannot convert array to object"); }
        virtual JSON_FLOAT &getFloat() override { throw std::runtime_error("Cannot convert array to float"); }
        virtual JSON_INT &getInt() override { throw std::runtime_error("Cannot convert array to int"); }
        virtual JSON_STRING &getString() override { throw std::runtime_error("Cannot convert array to string"); }
        virtual JSON_BOOL &getBool() override { throw std::runtime_error("Cannot convert array to bool"); }

    private:
        JSON_ARRAY _value;
    };
}

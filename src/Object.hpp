#pragma once

#include <memory>
#include "Json.hpp"

namespace jsoncpp
{
    class Object : public ijson
    {
    public:
        Object();
        Object(const JSON_OBJECT &value) = delete;
        Object(JSON_OBJECT &&value);
        Object(const Object &other) = delete;
        Object(Object &&other);
        Object &operator=(const Object &other) = delete;
        Object &operator=(Object &&other);
        virtual ~Object() = default;

        virtual std::string toString(int indent = -1) const override;

        virtual const JSON_TYPE &operator[](const std::string &key) const override { return _value.at(key); }
        virtual const JSON_TYPE &operator[](const char *key) const override { return _value.at(key); }
        virtual const JSON_TYPE &operator[](size_t index) const override { throw std::runtime_error("Cannot use int as object key"); }

        virtual JSON_TYPE &operator[](const std::string &key) override { return _value[key]; }
        virtual JSON_TYPE &operator[](const char *key) override { return _value[key]; }
        virtual JSON_TYPE &operator[](size_t index) override { throw std::runtime_error("Cannot use int as object key"); }

        virtual ijson &operator=(const ijson &other) override;
        virtual ijson &operator=(ijson &&other) override;

        virtual const JSON_ARRAY &getArray() const override { throw std::runtime_error("Cannot convert object to array"); }
        virtual const JSON_OBJECT &getObject() const override { return _value; }
        virtual JSON_FLOAT getFloat() const override { throw std::runtime_error("Cannot convert object to float"); }
        virtual JSON_INT getInt() const override { throw std::runtime_error("Cannot convert object to int"); }
        virtual JSON_STRING getString() const override { throw std::runtime_error("Cannot convert object to string"); }
        virtual JSON_BOOL getBool() const override { throw std::runtime_error("Cannot convert object to bool"); }

        virtual JSON_ARRAY &getArray() override { throw std::runtime_error("Cannot convert object to array"); }
        virtual JSON_OBJECT &getObject() override { return _value; }
        virtual JSON_FLOAT &getFloat() override { throw std::runtime_error("Cannot convert object to float"); }
        virtual JSON_INT &getInt() override { throw std::runtime_error("Cannot convert object to int"); }
        virtual JSON_STRING &getString() override { throw std::runtime_error("Cannot convert object to string"); }
        virtual JSON_BOOL &getBool() override { throw std::runtime_error("Cannot convert object to bool"); }

    private:
        JSON_OBJECT _value;
    };
}

#pragma once

#include <memory>
#include "Json.hpp"

namespace jsoncpp
{
    class String : public ijson
    {
    public:
        String();
        String(const JSON_STRING &value);
        String(const String &other);
        String(String &&other);
        String &operator=(const String &other);
        String &operator=(String &&other);
        ~String() = default;

        virtual std::string toString(int indent = -1) const override;

        virtual const ijson &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual const ijson &operator[](const char *key) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual const ijson &operator[](size_t index) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }

        virtual ijson &operator[](const std::string &key) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual ijson &operator[](const char *key) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual ijson &operator[](size_t index) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }

        virtual ijson &operator=(const ijson &other) override;
        virtual ijson &operator=(ijson &&other) override;

        virtual const JSON_ARRAY &getArray() const override { throw std::runtime_error("Cannot convert string to array"); }
        virtual const JSON_OBJECT &getObject() const override { throw std::runtime_error("Cannot convert string to object"); }
        virtual JSON_FLOAT getFloat() const override { throw std::runtime_error("Cannot convert string to float"); }
        virtual JSON_INT getInt() const override { throw std::runtime_error("Cannot convert string to int"); }
        virtual JSON_STRING getString() const override { return _value; }
        virtual JSON_BOOL getBool() const override { throw std::runtime_error("Cannot convert string to bool"); }

        virtual JSON_ARRAY &getArray() override { throw std::runtime_error("Cannot convert string to array"); }
        virtual JSON_OBJECT &getObject() override { throw std::runtime_error("Cannot convert string to object"); }
        virtual JSON_FLOAT &getFloat() override { throw std::runtime_error("Cannot convert string to float"); }
        virtual JSON_INT &getInt() override { throw std::runtime_error("Cannot convert string to int"); }
        virtual JSON_STRING &getString() override { return _value; }
        virtual JSON_BOOL &getBool() override { throw std::runtime_error("Cannot convert string to bool"); }

    private:
        JSON_STRING _value;
    };
}

#pragma once

#include <memory>
#include "Json.hpp"

namespace jsoncpp
{
    class Int : public ijson
    {
    public:
        Int();
        Int(JSON_INT value);
        Int(const Int &other);
        Int(Int &&other);
        Int &operator=(const Int &other);
        Int &operator=(Int &&other);
        virtual ~Int() = default;

        virtual std::string toString(int indent = -1) const override;

        virtual const ijson &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual const ijson &operator[](const char *key) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual const ijson &operator[](size_t index) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }

        virtual ijson &operator[](const std::string &key) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual ijson &operator[](const char *key) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual ijson &operator[](size_t index) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }

        virtual ijson &operator=(const ijson &other) override;
        virtual ijson &operator=(ijson &&other) override;

        virtual const JSON_ARRAY &getArray() const override { throw std::runtime_error("Cannot convert int to array"); }
        virtual const JSON_OBJECT &getObject() const override { throw std::runtime_error("Cannot convert int to object"); }
        virtual JSON_FLOAT getFloat() const override { throw std::runtime_error("Cannot convert int to float"); }
        virtual JSON_INT getInt() const override { return _value; }
        virtual JSON_STRING getString() const override { throw std::runtime_error("Cannot convert int to string"); }
        virtual JSON_BOOL getBool() const override { throw std::runtime_error("Cannot convert int to bool"); }

        virtual JSON_ARRAY &getArray() override { throw std::runtime_error("Cannot convert int to array"); }
        virtual JSON_OBJECT &getObject() override { throw std::runtime_error("Cannot convert int to object"); }
        virtual JSON_FLOAT &getFloat() override { throw std::runtime_error("Cannot convert int to float"); }
        virtual JSON_INT &getInt() override { return _value; }
        virtual JSON_STRING &getString() override { throw std::runtime_error("Cannot convert int to string"); }
        virtual JSON_BOOL &getBool() override { throw std::runtime_error("Cannot convert int to bool"); }

    private:
        JSON_INT _value;
    };
}

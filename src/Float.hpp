#pragma once

#include <memory>
#include "Json.hpp"

namespace jsoncpp
{
    class Float : public ijson
    {
    public:
        Float();
        Float(JSON_FLOAT value);
        Float(const Float &other);
        Float(Float &&other);
        Float &operator=(const Float &other);
        Float &operator=(Float &&other);
        virtual ~Float() = default;

        virtual std::string toString(int indent = -1) const override;

        virtual const ijson &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual const ijson &operator[](const char *key) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual const ijson &operator[](size_t index) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }

        virtual ijson &operator[](const std::string &key) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual ijson &operator[](const char *key) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual ijson &operator[](size_t index) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }

        virtual ijson &operator=(const ijson &other) override;
        virtual ijson &operator=(ijson &&other) override;

        virtual const JSON_ARRAY &getArray() const override { throw std::runtime_error("Cannot convert float to array"); }
        virtual const JSON_OBJECT &getObject() const override { throw std::runtime_error("Cannot convert float to object"); }
        virtual JSON_FLOAT getFloat() const override { return _value; }
        virtual JSON_INT getInt() const override { throw std::runtime_error("Cannot convert float to int"); }
        virtual JSON_STRING getString() const override { throw std::runtime_error("Cannot convert float to string"); }
        virtual JSON_BOOL getBool() const override { throw std::runtime_error("Cannot convert float to bool"); }

        virtual JSON_ARRAY &getArray() override { throw std::runtime_error("Cannot convert float to array"); }
        virtual JSON_OBJECT &getObject() override { throw std::runtime_error("Cannot convert float to object"); }
        virtual JSON_FLOAT &getFloat() override { return _value; }
        virtual JSON_INT &getInt() override { throw std::runtime_error("Cannot convert float to int"); }
        virtual JSON_STRING &getString() override { throw std::runtime_error("Cannot convert float to string"); }
        virtual JSON_BOOL &getBool() override { throw std::runtime_error("Cannot convert float to bool"); }

    private:
        JSON_FLOAT _value;
    };
}

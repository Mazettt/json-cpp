#pragma once

#include <memory>
#include "Json.hpp"

namespace jsoncpp
{
    class Bool : public ijson
    {
    public:
        Bool();
        Bool(JSON_BOOL value);
        Bool(const Bool &other);
        Bool(Bool &&other);
        Bool &operator=(const Bool &other);
        Bool &operator=(Bool &&other);
        ~Bool() = default;

        virtual std::string toString(int indent = -1) const override;

        virtual const ijson &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual const ijson &operator[](const char *key) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual const ijson &operator[](size_t index) const override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }

        virtual ijson &operator[](const std::string &key) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual ijson &operator[](const char *key) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }
        virtual ijson &operator[](size_t index) override { throw std::runtime_error("Cannot use index operator in a non-iterable type"); }

        virtual ijson &operator=(const ijson &other) override;
        virtual ijson &operator=(ijson &&other) override;

        virtual const JSON_ARRAY &getArray() const override { throw std::runtime_error("Cannot convert bool to array"); }
        virtual const JSON_OBJECT &getObject() const override { throw std::runtime_error("Cannot convert bool to object"); }
        virtual JSON_FLOAT getFloat() const override { throw std::runtime_error("Cannot convert bool to float"); }
        virtual JSON_INT getInt() const override { throw std::runtime_error("Cannot convert bool to int"); }
        virtual JSON_STRING getString() const override { throw std::runtime_error("Cannot convert bool to string"); }
        virtual JSON_BOOL getBool() const override { return _value; }

        virtual JSON_ARRAY &getArray() override { throw std::runtime_error("Cannot convert bool to array"); }
        virtual JSON_OBJECT &getObject() override { throw std::runtime_error("Cannot convert bool to object"); }
        virtual JSON_FLOAT &getFloat() override { throw std::runtime_error("Cannot convert bool to float"); }
        virtual JSON_INT &getInt() override { throw std::runtime_error("Cannot convert bool to int"); }
        virtual JSON_STRING &getString() override { throw std::runtime_error("Cannot convert bool to string"); }
        virtual JSON_BOOL &getBool() override { return _value; }

    private:
        JSON_BOOL _value;
    };
}

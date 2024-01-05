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

        virtual std::string toString(int indent = 0, int __baseIndent = 0) const override;

        // array
        virtual const JSON_TYPE &operator[](size_t index) const override { throw std::runtime_error("Cannot use operator[] on int"); }
        virtual JSON_TYPE &operator[](size_t index) override { throw std::runtime_error("Cannot use operator[] on int"); }
        virtual void push(JSON_TYPE &&value) override { throw std::runtime_error("Cannot use push() on int"); }
        virtual void insert(size_t index, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on int"); }
        virtual void erase(size_t index) override { throw std::runtime_error("Cannot use erase() on int"); }
        virtual const JSON_TYPE &at(size_t index) const override { throw std::runtime_error("Cannot use at() on int"); }
        virtual JSON_TYPE &at(size_t index) override { throw std::runtime_error("Cannot use at() on int"); }
        virtual const JSON_TYPE &front() const override { throw std::runtime_error("Cannot use front() on int"); }
        virtual JSON_TYPE &front() override { throw std::runtime_error("Cannot use front() on int"); }
        virtual const JSON_TYPE &back() const override { throw std::runtime_error("Cannot use back() on int"); }
        virtual JSON_TYPE &back() override { throw std::runtime_error("Cannot use back() on int"); }

        // object
        virtual const JSON_TYPE &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use operator[] on int"); }
        virtual JSON_TYPE &operator[](const std::string &key) override { throw std::runtime_error("Cannot use operator[] on int"); }
        virtual const JSON_TYPE &operator[](const char *key) const override { throw std::runtime_error("Cannot use operator[] on int"); }
        virtual JSON_TYPE &operator[](const char *key) override { throw std::runtime_error("Cannot use operator[] on int"); }
        virtual void insert(const std::string &key, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on int"); }
        virtual bool contains(const std::string &key) const override { throw std::runtime_error("Cannot use contains() on int"); }
        virtual void erase(const std::string &key) override { throw std::runtime_error("Cannot use erase() on int"); }
        virtual const JSON_TYPE &at(const std::string &key) const override { throw std::runtime_error("Cannot use at() on int"); }
        virtual JSON_TYPE &at(const std::string &key) override { throw std::runtime_error("Cannot use at() on int"); }

        // both array and object
        virtual void clear() override { throw std::runtime_error("Cannot use clear() on int"); }
        virtual size_t size() const override { throw std::runtime_error("Cannot use size() on int"); }
        virtual bool empty() const override { throw std::runtime_error("Cannot use empty() on int"); }

        // conversion
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

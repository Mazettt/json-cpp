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
        virtual ~String() = default;

        virtual std::string toString(int indent = 0, int __baseIndent = 0) const override;

        // array
        virtual const JSON_TYPE &operator[](size_t index) const override { throw std::runtime_error("Cannot use operator[] on string"); }
        virtual JSON_TYPE &operator[](size_t index) override { throw std::runtime_error("Cannot use operator[] on string"); }
        virtual void push(JSON_TYPE &&value) override { throw std::runtime_error("Cannot use push() on string"); }
        virtual void insert(size_t index, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on string"); }
        virtual void erase(size_t index) override { throw std::runtime_error("Cannot use erase() on string"); }
        virtual const JSON_TYPE &at(size_t index) const override { throw std::runtime_error("Cannot use at() on string"); }
        virtual JSON_TYPE &at(size_t index) override { throw std::runtime_error("Cannot use at() on string"); }
        virtual const JSON_TYPE &front() const override { throw std::runtime_error("Cannot use front() on string"); }
        virtual JSON_TYPE &front() override { throw std::runtime_error("Cannot use front() on string"); }
        virtual const JSON_TYPE &back() const override { throw std::runtime_error("Cannot use back() on string"); }
        virtual JSON_TYPE &back() override { throw std::runtime_error("Cannot use back() on string"); }

        // object
        virtual const JSON_TYPE &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use operator[] on string"); }
        virtual JSON_TYPE &operator[](const std::string &key) override { throw std::runtime_error("Cannot use operator[] on string"); }
        virtual const JSON_TYPE &operator[](const char *key) const override { throw std::runtime_error("Cannot use operator[] on string"); }
        virtual JSON_TYPE &operator[](const char *key) override { throw std::runtime_error("Cannot use operator[] on string"); }
        virtual void insert(const std::string &key, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on string"); }
        virtual bool contains(const std::string &key) const override { throw std::runtime_error("Cannot use contains() on string"); }
        virtual void erase(const std::string &key) override { throw std::runtime_error("Cannot use erase() on string"); }
        virtual const JSON_TYPE &at(const std::string &key) const override { throw std::runtime_error("Cannot use at() on string"); }
        virtual JSON_TYPE &at(const std::string &key) override { throw std::runtime_error("Cannot use at() on string"); }

        // both array and object
        virtual void clear() override { throw std::runtime_error("Cannot use clear() on string"); }
        virtual size_t size() const override { throw std::runtime_error("Cannot use size() on string"); }
        virtual bool empty() const override { throw std::runtime_error("Cannot use empty() on string"); }

        // conversion
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

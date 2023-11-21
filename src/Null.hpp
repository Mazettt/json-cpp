#pragma once

#include <memory>
#include "Json.hpp"

namespace jsoncpp
{
    class Null : public ijson
    {
    public:
        Null() = default;
        Null(const Null &other) = default;
        Null(Null &&other) = default;
        Null &operator=(const Null &other) = default;
        Null &operator=(Null &&other) = default;
        virtual ~Null() = default;

        virtual std::string toString(int indent = -1) const override;

        // array
        virtual const JSON_TYPE &operator[](size_t index) const override { throw std::runtime_error("Cannot use operator[] on null"); }
        virtual JSON_TYPE &operator[](size_t index) override { throw std::runtime_error("Cannot use operator[] on null"); }
        virtual void push(JSON_TYPE &&value) override { throw std::runtime_error("Cannot use push() on null"); }
        virtual void insert(size_t index, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on null"); }
        virtual void erase(size_t index) override { throw std::runtime_error("Cannot use erase() on null"); }
        virtual const JSON_TYPE &at(size_t index) const override { throw std::runtime_error("Cannot use at() on null"); }
        virtual JSON_TYPE &at(size_t index) override { throw std::runtime_error("Cannot use at() on null"); }
        virtual const JSON_TYPE &front() const override { throw std::runtime_error("Cannot use front() on null"); }
        virtual JSON_TYPE &front() override { throw std::runtime_error("Cannot use front() on null"); }
        virtual const JSON_TYPE &back() const override { throw std::runtime_error("Cannot use back() on null"); }
        virtual JSON_TYPE &back() override { throw std::runtime_error("Cannot use back() on null"); }

        // object
        virtual const JSON_TYPE &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use operator[] on null"); }
        virtual JSON_TYPE &operator[](const std::string &key) override { throw std::runtime_error("Cannot use operator[] on null"); }
        virtual const JSON_TYPE &operator[](const char *key) const override { throw std::runtime_error("Cannot use operator[] on null"); }
        virtual JSON_TYPE &operator[](const char *key) override { throw std::runtime_error("Cannot use operator[] on null"); }
        virtual void insert(const std::string &key, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on null"); }
        virtual bool contains(const std::string &key) const override { throw std::runtime_error("Cannot use contains() on null"); }
        virtual void erase(const std::string &key) override { throw std::runtime_error("Cannot use erase() on null"); }
        virtual const JSON_TYPE &at(const std::string &key) const override { throw std::runtime_error("Cannot use at() on null"); }
        virtual JSON_TYPE &at(const std::string &key) override { throw std::runtime_error("Cannot use at() on null"); }

        // both array and object
        virtual void clear() override { throw std::runtime_error("Cannot use clear() on null"); }
        virtual size_t size() const override { throw std::runtime_error("Cannot use size() on null"); }
        virtual bool empty() const override { throw std::runtime_error("Cannot use empty() on null"); }

        // conversion
        virtual const JSON_ARRAY &getArray() const override { throw std::runtime_error("Cannot convert null to array"); }
        virtual const JSON_OBJECT &getObject() const override { throw std::runtime_error("Cannot convert null to object"); }
        virtual JSON_FLOAT getFloat() const override { throw std::runtime_error("Cannot convert null to float"); }
        virtual JSON_INT getInt() const override { throw std::runtime_error("Cannot convert null to int"); }
        virtual JSON_STRING getString() const override { throw std::runtime_error("Cannot convert null to string"); }
        virtual JSON_BOOL getBool() const override { throw std::runtime_error("Cannot convert null to bool"); }

        virtual JSON_ARRAY &getArray() override { throw std::runtime_error("Cannot convert null to array"); }
        virtual JSON_OBJECT &getObject() override { throw std::runtime_error("Cannot convert null to object"); }
        virtual JSON_FLOAT &getFloat() override { throw std::runtime_error("Cannot convert null to float"); }
        virtual JSON_INT &getInt() override { throw std::runtime_error("Cannot convert null to int"); }
        virtual JSON_STRING &getString() override { throw std::runtime_error("Cannot convert null to string"); }
        virtual JSON_BOOL &getBool() override { throw std::runtime_error("Cannot convert null to bool"); }
    };
}

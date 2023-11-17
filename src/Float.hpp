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

        // array
        virtual const JSON_TYPE &operator[](size_t index) const override { throw std::runtime_error("Cannot use operator[] on float"); }
        virtual JSON_TYPE &operator[](size_t index) override { throw std::runtime_error("Cannot use operator[] on float"); }
        virtual void push(JSON_TYPE &&value) override { throw std::runtime_error("Cannot use push() on float"); }
        virtual void insert(size_t index, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on float"); }
        virtual void erase(size_t index) override { throw std::runtime_error("Cannot use erase() on float"); }
        virtual const JSON_TYPE &at(size_t index) const override { throw std::runtime_error("Cannot use at() on float"); }
        virtual JSON_TYPE &at(size_t index) override { throw std::runtime_error("Cannot use at() on float"); }
        virtual const JSON_TYPE &front() const override { throw std::runtime_error("Cannot use front() on float"); }
        virtual JSON_TYPE &front() override { throw std::runtime_error("Cannot use front() on float"); }
        virtual const JSON_TYPE &back() const override { throw std::runtime_error("Cannot use back() on float"); }
        virtual JSON_TYPE &back() override { throw std::runtime_error("Cannot use back() on float"); }

        // object
        virtual const JSON_TYPE &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use operator[] on float"); }
        virtual JSON_TYPE &operator[](const std::string &key) override { throw std::runtime_error("Cannot use operator[] on float"); }
        virtual const JSON_TYPE &operator[](const char *key) const override { throw std::runtime_error("Cannot use operator[] on float"); }
        virtual JSON_TYPE &operator[](const char *key) override { throw std::runtime_error("Cannot use operator[] on float"); }
        virtual void insert(const std::string &key, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on float"); }
        virtual bool contains(const std::string &key) const override { throw std::runtime_error("Cannot use contains() on float"); }
        virtual void erase(const std::string &key) override { throw std::runtime_error("Cannot use erase() on float"); }
        virtual const JSON_TYPE &at(const std::string &key) const override { throw std::runtime_error("Cannot use at() on float"); }
        virtual JSON_TYPE &at(const std::string &key) override { throw std::runtime_error("Cannot use at() on float"); }

        // both array and object
        virtual void clear() override { throw std::runtime_error("Cannot use clear() on float"); }
        virtual size_t size() const override { throw std::runtime_error("Cannot use size() on float"); }
        virtual bool empty() const override { throw std::runtime_error("Cannot use empty() on float"); }

        // conversion
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

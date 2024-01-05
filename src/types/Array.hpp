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

        virtual std::string toString(int indent = 0, int __baseIndent = 0) const override;

        // array
        virtual const JSON_TYPE &operator[](size_t index) const override { return _value[index]; }
        virtual JSON_TYPE &operator[](size_t index) override { return _value[index]; }
        virtual void push(JSON_TYPE &&value) override { _value.push_back(std::move(value)); }
        virtual void insert(size_t index, JSON_TYPE &&value) override { _value.insert(_value.begin() + index, std::move(value)); }
        virtual void erase(size_t index) override { _value.erase(_value.begin() + index); }
        virtual const JSON_TYPE &at(size_t index) const override { return _value.at(index); }
        virtual JSON_TYPE &at(size_t index) override { return _value.at(index); }
        virtual const JSON_TYPE &front() const override { return _value.front(); }
        virtual JSON_TYPE &front() override { return _value.front(); }
        virtual const JSON_TYPE &back() const override { return _value.back(); }
        virtual JSON_TYPE &back() override { return _value.back(); }

        // object
        virtual const JSON_TYPE &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use string as array index"); }
        virtual JSON_TYPE &operator[](const std::string &key) override { throw std::runtime_error("Cannot use string as array index"); }
        virtual const JSON_TYPE &operator[](const char *key) const override { throw std::runtime_error("Cannot use string as array index"); }
        virtual JSON_TYPE &operator[](const char *key) override { throw std::runtime_error("Cannot use string as array index"); }
        virtual void insert(const std::string &key, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on array"); }
        virtual bool contains(const std::string &key) const override { throw std::runtime_error("Cannot use contains() on array"); }
        virtual void erase(const std::string &key) override { throw std::runtime_error("Cannot use erase() on array"); }
        virtual const JSON_TYPE &at(const std::string &key) const override { throw std::runtime_error("Cannot use string as array index"); }
        virtual JSON_TYPE &at(const std::string &key) override { throw std::runtime_error("Cannot use string as array index"); }

        // both array and object
        virtual void clear() override { _value.clear(); }
        virtual size_t size() const override { return _value.size(); }
        virtual bool empty() const override { return _value.empty(); }

        // conversion
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

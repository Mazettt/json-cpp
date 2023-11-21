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

        virtual std::string toString(int indent = 0, int __baseIndent = 0) const override;

        // array
        virtual const JSON_TYPE &operator[](size_t index) const override { throw std::runtime_error("Cannot use int as object key"); }
        virtual JSON_TYPE &operator[](size_t index) override { throw std::runtime_error("Cannot use int as object key"); }
        virtual void push(JSON_TYPE &&value) override { throw std::runtime_error("Cannot use push() on object"); }
        virtual void insert(size_t index, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on object"); }
        virtual void erase(size_t index) override { throw std::runtime_error("Cannot use erase() on object"); }
        virtual const JSON_TYPE &at(size_t index) const override { throw std::runtime_error("Cannot use int as object key"); }
        virtual JSON_TYPE &at(size_t index) override { throw std::runtime_error("Cannot use int as object key"); }
        virtual const JSON_TYPE &front() const override { throw std::runtime_error("Cannot use front() on object"); }
        virtual JSON_TYPE &front() override { throw std::runtime_error("Cannot use front() on object"); }
        virtual const JSON_TYPE &back() const override { throw std::runtime_error("Cannot use back() on object"); }
        virtual JSON_TYPE &back() override { throw std::runtime_error("Cannot use back() on object"); }

        // object
        virtual const JSON_TYPE &operator[](const std::string &key) const override { return _value.at(key); }
        virtual JSON_TYPE &operator[](const std::string &key) override { return _value[key]; }
        virtual const JSON_TYPE &operator[](const char *key) const override { return _value.at(key); }
        virtual JSON_TYPE &operator[](const char *key) override { return _value[key]; }
        virtual void insert(const std::string &key, JSON_TYPE &&value) override { _value.insert(std::make_pair(key, std::move(value))); }
        virtual bool contains(const std::string &key) const override { return _value.find(key) != _value.end(); }
        virtual void erase(const std::string &key) override { _value.erase(key); }
        virtual const JSON_TYPE &at(const std::string &key) const override { return _value.at(key); }
        virtual JSON_TYPE &at(const std::string &key) override { return _value.at(key); }

        // both array and object
        virtual void clear() override { _value.clear(); }
        virtual size_t size() const override { return _value.size(); }
        virtual bool empty() const override { return _value.empty(); }

        // conversion
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

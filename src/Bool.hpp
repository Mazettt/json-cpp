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
        virtual ~Bool() = default;

        virtual std::string toString(int indent = -1) const override;

        // array
        virtual const JSON_TYPE &operator[](size_t index) const override { throw std::runtime_error("Cannot use operator[] on bool"); }
        virtual JSON_TYPE &operator[](size_t index) override { throw std::runtime_error("Cannot use operator[] on bool"); }
        virtual void push(JSON_TYPE &&value) override { throw std::runtime_error("Cannot use push() on bool"); }
        virtual void insert(size_t index, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on bool"); }
        virtual void erase(size_t index) override { throw std::runtime_error("Cannot use erase() on bool"); }
        virtual const JSON_TYPE &at(size_t index) const override { throw std::runtime_error("Cannot use at() on bool"); }
        virtual JSON_TYPE &at(size_t index) override { throw std::runtime_error("Cannot use at() on bool"); }
        virtual const JSON_TYPE &front() const override { throw std::runtime_error("Cannot use front() on bool"); }
        virtual JSON_TYPE &front() override { throw std::runtime_error("Cannot use front() on bool"); }
        virtual const JSON_TYPE &back() const override { throw std::runtime_error("Cannot use back() on bool"); }
        virtual JSON_TYPE &back() override { throw std::runtime_error("Cannot use back() on bool"); }

        // object
        virtual const JSON_TYPE &operator[](const std::string &key) const override { throw std::runtime_error("Cannot use operator[] on bool"); }
        virtual JSON_TYPE &operator[](const std::string &key) override { throw std::runtime_error("Cannot use operator[] on bool"); }
        virtual const JSON_TYPE &operator[](const char *key) const override { throw std::runtime_error("Cannot use operator[] on bool"); }
        virtual JSON_TYPE &operator[](const char *key) override { throw std::runtime_error("Cannot use operator[] on bool"); }
        virtual void insert(const std::string &key, JSON_TYPE &&value) override { throw std::runtime_error("Cannot use insert() on bool"); }
        virtual bool contains(const std::string &key) const override { throw std::runtime_error("Cannot use contains() on bool"); }
        virtual void erase(const std::string &key) override { throw std::runtime_error("Cannot use erase() on bool"); }
        virtual const JSON_TYPE &at(const std::string &key) const override { throw std::runtime_error("Cannot use at() on bool"); }
        virtual JSON_TYPE &at(const std::string &key) override { throw std::runtime_error("Cannot use at() on bool"); }

        // both array and object
        virtual void clear() override { throw std::runtime_error("Cannot use clear() on bool"); }
        virtual size_t size() const override { throw std::runtime_error("Cannot use size() on bool"); }
        virtual bool empty() const override { throw std::runtime_error("Cannot use empty() on bool"); }

        // conversion
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

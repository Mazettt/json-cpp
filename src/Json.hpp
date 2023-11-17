#pragma once

#include "Types.hpp"

namespace jsoncpp
{
    class jsonptr;

    class ijson
    {
    public:
        class Error: public std::exception
        {
        public:
            Error(const std::string &message);
            virtual const char *what() const noexcept override;

        protected:
            std::string _msg;
        };

        virtual ~ijson() = default;

        virtual std::string toString(int indent = -1) const = 0;

        // array
        virtual const JSON_TYPE &operator[](size_t index) const = 0;
        virtual JSON_TYPE &operator[](size_t index) = 0;
        virtual void push(JSON_TYPE &&value) = 0;
        virtual void insert(size_t index, JSON_TYPE &&value) = 0;
        virtual void erase(size_t index) = 0;
        virtual const JSON_TYPE &at(size_t index) const = 0;
        virtual JSON_TYPE &at(size_t index) = 0;
        virtual const JSON_TYPE &front() const = 0;
        virtual JSON_TYPE &front() = 0;
        virtual const JSON_TYPE &back() const = 0;
        virtual JSON_TYPE &back() = 0;

        // object
        virtual const JSON_TYPE &operator[](const std::string &key) const = 0;
        virtual JSON_TYPE &operator[](const std::string &key) = 0;
        virtual const JSON_TYPE &operator[](const char *key) const = 0;
        virtual JSON_TYPE &operator[](const char *key) = 0;
        virtual void insert(const std::string &key, JSON_TYPE &&value) = 0;
        virtual bool contains(const std::string &key) const = 0;
        virtual void erase(const std::string &key) = 0;
        virtual const JSON_TYPE &at(const std::string &key) const = 0;
        virtual JSON_TYPE &at(const std::string &key) = 0;

        // both array and object
        virtual void clear() = 0;
        virtual size_t size() const = 0;
        virtual bool empty() const = 0;

        // conversion
        virtual const JSON_ARRAY &getArray() const = 0;
        virtual const JSON_OBJECT &getObject() const = 0;
        virtual JSON_FLOAT getFloat() const = 0;
        virtual JSON_INT getInt() const = 0;
        virtual JSON_STRING getString() const = 0;
        virtual JSON_BOOL getBool() const = 0;

        virtual JSON_ARRAY &getArray() = 0;
        virtual JSON_OBJECT &getObject() = 0;
        virtual JSON_FLOAT &getFloat() = 0;
        virtual JSON_INT &getInt() = 0;
        virtual JSON_STRING &getString() = 0;
        virtual JSON_BOOL &getBool() = 0;

        //! a voir
        // operator JSON_ARRAY () const { return getArray(); }
        // operator JSON_OBJECT () const { return getObject(); }
        // operator JSON_FLOAT () const { return getFloat(); }
        // operator JSON_INT () const { return getInt(); }
        // operator JSON_STRING () const { return getString(); }
        // operator JSON_BOOL () const { return getBool(); }

        // operator JSON_ARRAY &() { return getArray(); }
        // operator JSON_OBJECT &() { return getObject(); }
        // operator JSON_FLOAT &() { return getFloat(); }
        // operator JSON_INT &() { return getInt(); }
        // operator JSON_STRING &() { return getString(); }
        // operator JSON_BOOL &() { return getBool(); }
    };

    class jsonptr : public ijson
    {
    public:
        jsonptr();
        jsonptr(jsonptr &&other);
        jsonptr(std::unique_ptr<ijson> &&other);
        jsonptr &operator=(jsonptr &&other);
        jsonptr &operator=(std::unique_ptr<ijson> &&other);
        virtual ~jsonptr() = default;

        virtual std::string toString(int indent = -1) const override { return _value->toString(indent); }

        // array
        virtual const JSON_TYPE &operator[](size_t index) const override { return (*_value)[index]; }
        virtual JSON_TYPE &operator[](size_t index) override { return (*_value)[index]; }
        virtual void push(JSON_TYPE &&value) override { _value->push(std::move(value)); }
        virtual void insert(size_t index, JSON_TYPE &&value) override { _value->insert(index, std::move(value)); }
        virtual void erase(size_t index) override { _value->erase(index); }
        virtual const JSON_TYPE &at(size_t index) const override { return _value->at(index); }
        virtual JSON_TYPE &at(size_t index) override { return _value->at(index); }
        virtual const JSON_TYPE &front() const override { return _value->front(); }
        virtual JSON_TYPE &front() override { return _value->front(); }
        virtual const JSON_TYPE &back() const override { return _value->back(); }
        virtual JSON_TYPE &back() override { return _value->back(); }

        // object
        virtual const JSON_TYPE &operator[](const std::string &key) const override { return (*_value)[key]; }
        virtual JSON_TYPE &operator[](const std::string &key) override { return (*_value)[key]; }
        virtual const JSON_TYPE &operator[](const char *key) const override { return (*_value)[key]; }
        virtual JSON_TYPE &operator[](const char *key) override { return (*_value)[key]; }
        virtual void insert(const std::string &key, JSON_TYPE &&value) override { _value->insert(key, std::move(value)); }
        virtual bool contains(const std::string &key) const override { return _value->contains(key); }
        virtual void erase(const std::string &key) override { _value->erase(key); }
        virtual const JSON_TYPE &at(const std::string &key) const override { return _value->at(key); }
        virtual JSON_TYPE &at(const std::string &key) override { return _value->at(key); }

        // both array and object
        virtual void clear() override { _value->clear(); }
        virtual size_t size() const override { return _value->size(); }
        virtual bool empty() const override { return _value->empty(); }

        // conversion
        virtual const JSON_ARRAY &getArray() const override { return _value->getArray(); }
        virtual const JSON_OBJECT &getObject() const override { return _value->getObject(); }
        virtual JSON_FLOAT getFloat() const override { return _value->getFloat(); }
        virtual JSON_INT getInt() const override { return _value->getInt(); }
        virtual JSON_STRING getString() const override { return _value->getString(); }
        virtual JSON_BOOL getBool() const override { return _value->getBool(); }

        virtual JSON_ARRAY &getArray() override { return _value->getArray(); }
        virtual JSON_OBJECT &getObject() override { return _value->getObject(); }
        virtual JSON_FLOAT &getFloat() override { return _value->getFloat(); }
        virtual JSON_INT &getInt() override { return _value->getInt(); }
        virtual JSON_STRING &getString() override { return _value->getString(); }
        virtual JSON_BOOL &getBool() override { return _value->getBool(); }

    private:
        std::unique_ptr<ijson> _value;
    };
}

std::ostream &operator<<(std::ostream &os, const jsoncpp::ijson &json);
std::ostream &operator<<(std::ostream &os, const jsoncpp::jsonptr &json);

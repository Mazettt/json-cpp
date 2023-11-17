#pragma once

#include "defines.hpp"

namespace jsoncpp
{
    class ijson
    {
    public:
        class Error: public std::exception {
        public:
            Error(const std::string &message);
            virtual const char *what() const noexcept override;

        protected:
            std::string _msg;
        };

        virtual ~ijson() = default;
        virtual std::string toString(int indent = -1) const = 0;

        virtual const ijson &operator[](const std::string &key) const = 0;
        virtual const ijson &operator[](const char *key) const = 0;
        virtual const ijson &operator[](size_t index) const = 0;

        virtual ijson &operator[](const std::string &key) = 0;
        virtual ijson &operator[](const char *key) = 0;
        virtual ijson &operator[](size_t index) = 0;

        virtual ijson &operator=(const ijson &other) = 0;
        virtual ijson &operator=(ijson &&other) = 0;

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

    // template <typename T>
    // class json
    // {
    // public:
    //     json();
    //     json(T &&value);
    //     json(const json &other);
    //     json(json &&other);
    //     json &operator=(const json &other);
    //     json &operator=(json &&other);
    //     ~json();

    //     std::string toString(int indent = -1) const;

    //     json &operator[](const std::string &key);
    //     json &operator[](const char *key);
    //     json &operator[](size_t index);

    //     json &operator=(const T &value);
    //     json &operator=(T &&value);

    //     T operator T() const;

    // private:
    //     std::string _key;
    // };
}

// enum Type {
//     number,
//     string,
//     boolean,
//     array
//     object,
//     whitespace,
//     null
// };

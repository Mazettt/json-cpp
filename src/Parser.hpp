#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "Json.hpp"

namespace jsoncpp {
    class Parser {
        public:
            class Error: public std::exception
            {
            public:
                Error(size_t line, size_t column, const std::string &message);
                virtual const char *what() const noexcept override;

            protected:
                std::string _msg;
            };

            Parser(const std::string &str);
            Parser(std::ifstream &stream);
            ~Parser() = default;

            json parse();

        private:
            std::string _str;
            size_t _line = 1;
            size_t _column = 1;
            size_t _index = 0;

            void skip();
            JSON_STRING parseString();
            JSON_INT parseInt();
            JSON_FLOAT parseFloat();
            JSON_BOOL parseBool();
            std::nullptr_t parseNull();
            JSON_ARRAY parseArray();
            JSON_OBJECT parseObject();
    };
}

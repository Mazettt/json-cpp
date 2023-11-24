#include "Parser.hpp"

using namespace jsoncpp;

Parser::Error::Error(size_t line, size_t column, const std::string &message):
    _msg("parse error at line " + std::to_string(line) + ", column " + std::to_string(column) + ": " + message)
{}

const char *Parser::Error::what() const noexcept
{
    return _msg.c_str();
}

Parser::Parser(const std::string &str)
{
    _str = str;
}

Parser::Parser(std::ifstream &stream)
{
    std::string line;
    while (std::getline(stream, line)) {
        _str += line;
        _str += '\n';
    }
}

jsonptr Parser::parse()
{
    if (_index >= _str.size())
        throw Error(_line, _column, "unexpected end of file");
    if (_str[_index] == '"')
        return parseString();
    else if (_str[_index] == '-' || (_str[_index] >= '0' && _str[_index] <= '9')) {
        std::string sub = _str.substr(_index);
        if (sub.substr(0, sub.find(',') - 1).find('.') != std::string::npos)
            return parseFloat();
        else
            return parseInt();
    }
    else if (_str.substr(_index).find("true") == 0 || _str.substr(_index).find("false") == 0)
        return parseBool();
    else if (_str.substr(_index).find("null") == 0)
        return parseNull();
    else if (_str[_index] == '[')
        return parseArray();
    else if (_str[_index] == '{')
        return parseObject();
    else
        throw Error(_line, _column, "unexpected data type");
}

void Parser::skip()
{
    for (; _index < _str.size() && (_str[_index] == ' ' || _str[_index] == '\t' || _str[_index] == '\n' || _str[_index] == '\r'); _index++) {
        if (_str[_index] == '\n') {
            _line++;
            _column = 1;
        } else {
            _column++;
        }
    }
}

JSON_STRING Parser::parseString()
{
    std::string res;
    for (_index++; _index < _str.size() && _str[_index] != '"'; _index++, _column++) {
        if (_str[_index] == '\\') {
            //TODO
            throw Error(_line, _column, "escape characters are not supported yet");
        } else if (_str[_index] == '\n') {
            throw Error(_line, _column, "unexpected end of line");
        } else
            res += _str[_index];
    }
    if (_index >= _str.size())
        throw Error(_line, _column, "unexpected end of file");
    _index++;
    _column++;
    return res;
}

JSON_INT Parser::parseInt()
{
    std::istringstream iss(_str.substr(_index));
    JSON_INT res;
    if (!(iss >> res))
        throw Error(_line, _column, "invalid integer");
    _index += iss.tellg();
    _column += iss.tellg();
    return res;
}

JSON_FLOAT Parser::parseFloat()
{
    std::istringstream iss(_str.substr(_index));
    JSON_FLOAT res;
    if (!(iss >> res))
        throw Error(_line, _column, "invalid float");
    _index += iss.tellg();
    _column += iss.tellg();
    return res;
}

JSON_BOOL Parser::parseBool()
{
    if (_str.substr(_index, 4) == "true") {
        _index += 4;
        _column += 4;
        return true;
    } else if (_str.substr(_index, 5) == "false") {
        _index += 5;
        _column += 5;
        return false;
    } else
        throw Error(_line, _column, "invalid boolean");
}

std::nullptr_t Parser::parseNull()
{
    if (_str.substr(_index, 4) == "null") {
        _index += 4;
        _column += 4;
        return nullptr;
    } else
        throw Error(_line, _column, "invalid null");
}

JSON_ARRAY Parser::parseArray()
{
    JSON_ARRAY res;
    _index++;
    _column++;
    skip();
    if (_index >= _str.size())
        throw Error(_line, _column, "unexpected end of file");
    if (_str[_index] == ']') {
        _index++;
        _column++;
        return res;
    }
    while (true) {
        res.push_back(parse());
        skip();
        if (_index >= _str.size())
            throw Error(_line, _column, "unexpected end of file");
        if (_str[_index] == ']') {
            _index++;
            _column++;
            break;
        } else if (_str[_index] == ',') {
            _index++;
            _column++;
            skip();
            if (_index >= _str.size())
                throw Error(_line, _column, "unexpected end of file");
            if (_str[_index] == ']')
                throw Error(_line, _column, "expected value after ','");
        } else
            throw Error(_line, _column, "expected ',' or ']'");
    }
    return res;
}

JSON_OBJECT Parser::parseObject()
{
    JSON_OBJECT res;
    _index++;
    _column++;
    skip();
    if (_index >= _str.size())
        throw Error(_line, _column, "unexpected end of file");
    if (_str[_index] == '}') {
        _index++;
        _column++;
        return res;
    }
    while (true) {
        if (_str[_index] != '"')
            throw Error(_line, _column, "expected '\"'");
        JSON_STRING key = parseString();
        skip();
        if (_index >= _str.size())
            throw Error(_line, _column, "unexpected end of file");
        if (_str[_index] != ':')
            throw Error(_line, _column, "expected ':'");
        _index++;
        _column++;
        skip();
        res[key] = parse();
        skip();
        if (_index >= _str.size())
            throw Error(_line, _column, "unexpected end of file");
        if (_str[_index] == '}') {
            _index++;
            _column++;
            break;
        } else if (_str[_index] == ',') {
            _index++;
            _column++;
            skip();
            if (_index >= _str.size())
                throw Error(_line, _column, "unexpected end of file");
            if (_str[_index] == '}')
                throw Error(_line, _column, "expected value after ','");
        } else
            throw Error(_line, _column, "expected ',' or '}'");
    }
    return res;
}

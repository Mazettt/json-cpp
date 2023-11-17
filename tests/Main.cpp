#include <iostream>

#include "../src/Json.hpp"
#include "../src/Array.hpp"
#include "../src/Object.hpp"
#include "../src/Float.hpp"
#include "../src/Int.hpp"
#include "../src/String.hpp"
#include "../src/Bool.hpp"
#include "../src/Utils.hpp"

using namespace jsoncpp;

int main(void)
{
    json j = make_json<jsoncpp::Object>();
    j["pi"] = 3.14159f;
    j["happy"] = true;
    j["name"] = "Niels";
    json answer = make_json<jsoncpp::Object>();
    answer["everything"] = 42;
    j["answer"] = std::move(answer);
    json list = make_json<jsoncpp::Array>();
    list.push(1);
    list.push(0);
    list.push(2);
    j["list"] = std::move(list);
    json object = make_json<jsoncpp::Object>();
    object["currency"] = "USD";
    object["value"] = 42.99f;
    j["object"] = std::move(object);
    std::cout << j << std::endl;
    return 0;
}

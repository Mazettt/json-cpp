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
    j["answer"] = make_json<jsoncpp::Object>();
    j["answer"]["everything"] = 42;
    j["list"] = make_json<jsoncpp::Array>();
    j["list"].push(1);
    j["list"].push(0);
    j["list"].push(2);
    j["object"] = make_json<jsoncpp::Object>();
    j["object"]["currency"] = "USD";
    j["object"]["value"] = 42.99f;
    std::cout << j << std::endl;

    float pi = j["pi"];
    std::cout << pi << std::endl;

    return 0;
}

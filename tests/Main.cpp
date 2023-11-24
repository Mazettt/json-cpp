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
    {
        std::ifstream stream("test.json");
        try {
            json test = json::parse(stream);
            std::cout << test.toString(0) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        try {
            json test = json::parse(R"({"answer":{"everything":42},"happy":true,"list":[1,0,2],"name":"Nielsoui","nothing":null,"object":{"currency":"USD","value":42.990002},"pi":3.141590})");
            std::cout << test.toString(4) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        json a;
        std::cout << a << std::endl;
        json j = make_json<jsoncpp::Object>();
        j["pi"] = 3.14159f;
        j["happy"] = true;
        j["name"] = "Niels";
        j["nothing"] = nullptr;
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
        std::cout << j.toString(4) << std::endl;

        float pi = j["pi"];
        std::cout << pi << std::endl;

        Float pi2 = j["pi"];
        std::cout << pi2 << std::endl;
    }

    return 0;
}

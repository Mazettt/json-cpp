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
    j["pi"] = make_json<jsoncpp::Float>(3.14159);
    j["happy"] = make_json<jsoncpp::Bool>(true);
    j["name"] = make_json<jsoncpp::String>(std::string("Niels"));
    jsoncpp::Object answer;
    answer["everything"] = make_json<jsoncpp::Int>(42);
    j["answer"] = make_json<jsoncpp::Object>(std::move(answer));
    jsoncpp::Array list;
    list.push(make_json<jsoncpp::Int>(1));
    list.push(make_json<jsoncpp::Int>(0));
    list.push(make_json<jsoncpp::Int>(2));
    j["list"] = make_json<jsoncpp::Array>(std::move(list));
    jsoncpp::Object object;
    object["currency"] = make_json<jsoncpp::String>(std::string("USD"));
    object["value"] = make_json<jsoncpp::Float>(42.99);
    j["object"] = make_json<jsoncpp::Object>(std::move(object));
    std::cout << j << std::endl;
    return 0;
}

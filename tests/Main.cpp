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
    jsoncpp::Object o;
    o["pi"] = make_json<jsoncpp::Float>(3.14159);
    o["happy"] = make_json<jsoncpp::Bool>(true);
    o["name"] = make_json<jsoncpp::String>(std::string("Niels"));
    jsoncpp::Object answer;
    answer["everything"] = make_json<jsoncpp::Int>(42);
    o["answer"] = make_json<jsoncpp::Object>(std::move(answer));
    jsoncpp::Array list;
    list.getArray().push_back(make_json<jsoncpp::Int>(1));
    list.getArray().push_back(make_json<jsoncpp::Int>(0));
    list.getArray().push_back(make_json<jsoncpp::Int>(2));
    o["list"] = make_json<jsoncpp::Array>(std::move(list));
    jsoncpp::Object object;
    object["currency"] = make_json<jsoncpp::String>(std::string("USD"));
    object["value"] = make_json<jsoncpp::Float>(42.99);
    o["object"] = make_json<jsoncpp::Object>(std::move(object));
    json j = make_json<jsoncpp::Object>(std::move(o));
    std::cout << *j << std::endl;
    return 0;
}

#include <iostream>

#include "../src/Json.hpp"
#include "../src/Array.hpp"
#include "../src/Object.hpp"
#include "../src/Float.hpp"
#include "../src/Int.hpp"
#include "../src/String.hpp"
#include "../src/Bool.hpp"

using json = jsoncpp::ijson;

int main(void)
{
    jsoncpp::Object o;
    o.getObject()["pi"] = std::make_unique<jsoncpp::Float>(3.14159);
    o.getObject()["happy"] = std::make_unique<jsoncpp::Bool>(true);
    o.getObject()["name"] = std::make_unique<jsoncpp::String>("Niels");
    jsoncpp::Object answer;
    answer.getObject()["everything"] = std::make_unique<jsoncpp::Int>(42);
    o.getObject()["answer"] = std::make_unique<jsoncpp::Object>(answer);
    jsoncpp::Array list;
    list.getArray().push_back(std::make_unique<jsoncpp::Int>(1));
    list.getArray().push_back(std::make_unique<jsoncpp::Int>(0));
    list.getArray().push_back(std::make_unique<jsoncpp::Int>(2));
    o.getObject()["list"] = std::make_unique<jsoncpp::Array>(list);
    jsoncpp::Object object;
    object.getObject()["currency"] = std::make_unique<jsoncpp::String>("USD");
    object.getObject()["value"] = std::make_unique<jsoncpp::Float>(42.99);
    o.getObject()["object"] = std::make_unique<jsoncpp::Object>(object);
    std::unique_ptr<json> j = std::make_unique<jsoncpp::Object>(o);
    std::cout << j->toString() << std::endl;
    return 0;
}

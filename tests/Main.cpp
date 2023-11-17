#include <iostream>

#include "../src/Json.hpp"
#include "../src/Array.hpp"
#include "../src/Object.hpp"
#include "../src/Float.hpp"
#include "../src/Int.hpp"
#include "../src/String.hpp"
#include "../src/Bool.hpp"

using json = std::unique_ptr<jsoncpp::ijson>;

template<typename T>
json make_json(T &&value)
{
    return std::make_unique<T>(std::forward<T>(value));
}

int main(void)
{
    jsoncpp::Object o;
    o.getObject()["pi"] = make_json<jsoncpp::Float>(3.14159);
    o.getObject()["happy"] = make_json<jsoncpp::Bool>(true);
    o.getObject()["name"] = make_json<jsoncpp::String>("Niels");
    jsoncpp::Object answer;
    answer.getObject()["everything"] = make_json<jsoncpp::Int>(42);
    o.getObject()["answer"] = make_json<jsoncpp::Object>(std::move(answer));
    jsoncpp::Array list;
    list.getArray().push_back(make_json<jsoncpp::Int>(1));
    list.getArray().push_back(make_json<jsoncpp::Int>(0));
    list.getArray().push_back(make_json<jsoncpp::Int>(2));
    o.getObject()["list"] = make_json<jsoncpp::Array>(std::move(list));
    jsoncpp::Object object;
    object.getObject()["currency"] = make_json<jsoncpp::String>("USD");
    object.getObject()["value"] = make_json<jsoncpp::Float>(42.99);
    o.getObject()["object"] = make_json<jsoncpp::Object>(std::move(object));
    json j = make_json<jsoncpp::Object>(std::move(o));
    std::cout << j->toString() << std::endl;
    return 0;
}

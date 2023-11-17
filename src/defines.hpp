#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>

#define JSON_BOOL bool
#define JSON_INT int
#define JSON_FLOAT float
#define JSON_STRING std::string
#define JSON_ARRAY std::vector<std::shared_ptr<ijson>>
#define JSON_OBJECT std::map<std::string, std::shared_ptr<ijson>>

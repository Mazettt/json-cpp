#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>

#include "Json.hpp"
#include "Types.hpp"
#include "Array.hpp"
#include "Object.hpp"
#include "Bool.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "String.hpp"

namespace jsoncpp {
    using json = JSON_TYPE;

    template<typename T>
    json make_json(T &&value)
    {
        return std::make_unique<T>(std::forward<T>(value));
    }
}

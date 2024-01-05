# json-cpp

A library to use JSON objects in C++.

This library supports all the basic JSON types: null, boolean, number, string, array and object.

The types used in this library to store the datas are defined in the `src/TypesDef.hpp` file as follows:

```txt
null    -> nullptr
boolean -> bool
integer -> int
float   -> float
string  -> std::string
array   -> std::vector<json>
object  -> std::map<std::string, json>
```

## Run the tests

To test the library, you can first navigate to the tests directory:

```bash
cd tests
```

Then, you can build the project with:

```bash
mkdir build
cd build
cmake ..
make
cd ..
```

Finally, you can run the tests with:

```bash
./build/my_app
```

If you want to modify the tests to test your own code or view some examples, you can edit the `main.cpp` file.

The CMakelists.txt file in the `tests/` directory is a great example of how to compile the library in your own project.

## Usage examples

Here are some examples of how to use the library.

For all the examples, you first need to include the library:

```cpp
#include <json/json.hpp>
using namespace jsoncpp;
```

### Create a JSON object

```cpp
json test;
```

By default, the json object is set to null.

### Create a JSON object with a value

```cpp
json test = true;
// or
json test = 42;
// or
json test = 42.42;
// or
json test = "Hello World!";
```

If you want to set it to an empty object, you can do:

```cpp
json test = Object();
```

Or to an empty array:

```cpp
json test = Array();
```

### Add a value to a JSON object

```cpp
test["key1"] = "value1";
test["key2"] = "value2";
test["key3"] = "value3";
```

### Add a value to a JSON array

```cpp
test.push("value1");
test.push("value2");
test.push("value3");
```

### Create JSON object from a string

```cpp
json test = json::parse(R"(
    {
        "key1": "value1",
        "key2": "value2",
        "key3": "value3"
    }
)");
```

### Read from a JSON file

```cpp
std::ifstream input("test.json");
json test = json::parse(input);
```

### Write to a JSON file

```cpp
std::ofstream output("test_write.json");
output << test;
```
Result:
```json
{"key1": "value1","key2": "value2","key3": "value3"}
```

Or with indentation:

```cpp
std::ofstream output("test_write.json");
output << test.toString(4);
```
Result:
```json
{
    "key1": "value1",
    "key2": "value2",
    "key3": "value3"
}
```

### Convert to a string

```cpp
std::string str = test.toString();
```

Or with indentation:

```cpp
std::string str = test.toString(4);
```

### Get a value from a JSON

```cpp
bool &value = test;
// or
int &value = test;
// or
float &value = test;
// or
std::string &value = test;
// or
std::vector<json> &value = test;
// or
std::map<std::string, json> &value = test;
```

### Get a value from a JSON object

```cpp
bool &value = test["key1"];
// or
int &value = test["key1"];
// or
float &value = test["key1"];
// or
std::string &value = test["key1"];
// or
std::vector<json> &value = test["key1"];
// or
std::map<std::string, json> &value = test["key1"];
```

### Get a value from a JSON array

```cpp
bool &value = test[0];
// or
int &value = test[0];
// or
float &value = test[0];
// or
std::string &value = test[0];
// or
std::vector<json> &value = test[0];
// or
std::map<std::string, json> &value = test[0];
```

### Operations on objects

A lot of methods are available to manipulate JSON objects. Here are some examples:

```cpp
json test = Object();
test["key1"] = "value1";
test.insert("key2", "value2");
if (test.contains("key1"))
    std::cout << "key1 exists" << std::endl;
test.erase("key1");
test.at("key2") = "value3";
std::cout << test.size() << std::endl;
test.clear();
if (test.empty())
    std::cout << "test is empty" << std::endl;
```

### Operations on arrays

A lot of methods are available to manipulate JSON arrays. Here are some examples:

```cpp
json test = Array();
test.push("value1");
test.push("value2");
test.insert(1, "value4");
test.erase(1);
test.at(1) = "value5";
test.front() = "front";
test.back() = "back";
std::cout << test.size() << std::endl;
test.clear();
if (test.empty())
    std::cout << "test is empty" << std::endl;
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

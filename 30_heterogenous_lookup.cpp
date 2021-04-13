#include <string>
#include <string_view>
#include <unordered_map>
#include <iostream>

/**
int main() {
    std::unordered_map<std::string, int> table = {{ "one", 1 }, { "two", 2 }};
    table.find("three"); // OK。だが、std::string型の一時オブジェクトが作られる。
    std::string_view sv = "two";
    table.find(sv); // エラー。std::string_view型でのルックアップはできない。
    table.find(std::string(sv)); // OK。だが、std::string型の一次オブジェクトが作られる。
}
**/

struct string_compare {
    using is_transparent = void;
    bool operator()(std::string_view key, std::string_view s) const {
        return key == s;
    }
};

struct string_hash {
    using is_transparent = void;
    using transparent_key_equal = string_compare;
    std::size_t operator()(std::string_view s) const {
        return std::hash<std::string_view>{}(s);
    }
    std::size_t operator()(const std::string& s) const {
        return std::hash<std::string_view>{}(s);
    }
    std::size_t operator()(const char* s) const {
        return std::hash<std::string_view>{}(s);
    }
};

int main() {
    std::unordered_map<std::string, int, string_hash, string_compare> table 
            = {{ "one", 1 }, { "two", 2 }};
    auto res1 = table.find("three"); // OK。std::string型の一時オブジェクトは作られない。
    std::string_view sv = "two";
    auto res2 = table.find(sv); // OK。std::string型の一時オブジェクトは作られない。
}
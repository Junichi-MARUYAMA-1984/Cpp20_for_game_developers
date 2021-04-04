#include <iostream>
#include <string>
#include <variant>

int main() {
    std::variant<std::string, double, bool> v1 = 3.14, v2 = std::string("Hello");

    // 保持している型を型リストのindexで返す。
    // ここでは、stringの場合は0, doubleの場合は1, boolの場合は2
    if (v1.index() == 1) {
        std::cout << std::get<1>(v1) << std::endl; // 3.14
    }

    // 保持している型が、ある型に一致するか否かを返す
    if (std::holds_alternative<std::string>(v2)) {
        std::cout << std::get<std::string>(v2) << std::endl; // Hello
    }

    // 保持する型をbool型の値に変更。
    // std::stringオブジェクトは破棄される。
    v2 = true;
    std::cout << v2.index() << std::endl; // 2
}
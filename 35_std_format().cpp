#include <string>
#include <format>
#include <iostream>

int main() {
    std::string a = std::format("C++{}", 20); // C++20
    std::cout << a << std::endl;
}
#include <iostream>
#include <charconv>

int main() {
    constexpr char s1[] = "3.14159265358979323";
    double r1;

    if (auto [ptr, e] = std::from_chars(std::begin(s1), std::end(s1), r1); e == std::errc{}) {
        std::cout << r1 << std::endl; // 3.14159
    }

    constexpr char s2[] = "80FFFFFF";
    unsigned r2;

    if (auto [ptr, e] = std::from_chars(std::begin(s2), std::end(s2),
        r2, 16); e == std::errc{}) {
        std::cout << r2 << std::endl; // 216426083
    }
}
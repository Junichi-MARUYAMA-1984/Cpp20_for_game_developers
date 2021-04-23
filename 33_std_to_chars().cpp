#include <iostream>
#include <limits>
#include <charconv>
#include <string_view>

int main() {
    double x = 3.141593;
    char buf[std::numeric_limits<double>::max_digits10]{};

    // 変換に成功した場合、ptrは返還後の文字列の終端を指す。
    // null終端にはされない。
    if (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf), x); e == std::errc{}) {
        std::cout << std::string_view(buf, ptr - buf) << std::endl; // 3.141593
    }

    if (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf), x,
            std::chars_format::scientific, 8); e == std::errc{}) {
        std::cout << std::string_view(buf, ptr - buf) << std::endl; // 3.141593e+00
    }
}
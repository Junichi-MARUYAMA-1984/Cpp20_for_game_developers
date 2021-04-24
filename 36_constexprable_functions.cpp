#include <iostream>
#include <string_view>
#include <algorithm>
#include <array>
#include <utility>
#include <ranges>

constexpr std::pair<std::string_view, std::string_view> Split(std::string_view s) {
    const auto dot = s.find_last_of(U'.');
    if (dot == std::string_view::npos) {
        return { {}, s };
    } else {
        return { std::string_view{ s.data(), dot },
                 std::string_view{ s.data() + dot + 1, (s.size() - dot - 1)} };
    }
}

constexpr std::array<int, 4> Sort(std::array<int, 4> a) {
    std::ranges::sort(a);
    return a;
}

int main() {
    // コンパイル時にファイル名と拡張子に分割する関数
    constexpr std::pair<std::string_view, std::string_view>
        path_extension = Split("aaa.txt");
    std::cout << path_extension.first << std::endl;
    std::cout << path_extension.second << std::endl;

    // コンパイル時にソートする関数
    constexpr auto sorted = Sort({ 15, 30, 10, 5 });
    for (const auto& n : sorted) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
}
#include <iostream>
#include <optional>

int main() {
    std::optional<int> oi; // デフォルトでは無効値
    std::optional<int> oi2 = 200; // 有効値を与える

    if (oi) {
        std::cout << *oi << std::endl; // 実行されない
    }

    if (oi2) {
        std::cout << *oi2 << std::endl; // 実行される: 200
    }

    oi = 100; // 有効値を代入
    oi2.reset(); // 無効値にする
    oi2 = std::nullopt; // 定数 std::nullopt は無効値を表す

    if (oi) {
        std::cout << *oi << std::endl; // 実行される: 100
    }

    if (oi2) {
        std::cout << *oi2 << std::endl; // 実行されない
    }

    std::cout << oi.value_or(-1) << std::endl; // 100
    std::cout << oi2.value_or(-1) << std::endl; // -1

    std::cout << std::boolalpha;
    std::cout << (oi == std::nullopt) << std::endl; // false
    std::cout << (oi2 == std::nullopt) << std::endl; // true
    std::cout << (oi == 200) << std::endl; // false
    std::cout << (oi != 0) << std::endl; // true
    std::cout << (oi2 > 0) << std::endl; // false
    std::cout << (oi2 != 0) << std::endl; // true
}
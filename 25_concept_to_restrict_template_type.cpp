#include <cmath>
#include <iostream>
#include <type_traits> // C++17までの例で用いる
#include <concepts> // C++20の例で用いる
using namespace std::literals; // string型を明示する s サフィックスを利用するために必要

/**
// C++17までは、テンプレートの方に制約を加えるためにSFINAEを用いる必要があった。

template <class T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
T Mod(T x, T y) { // ^^^ T を整数型に制約している
    return x % y;
}

template <class T, std::enable_if_t<std::is_floating_point_v<T>>* = nullptr>
T Mod(T x, T y) { // ^^^ T を浮動小数点型に制約している
    return fmod(x, y);
}

int main() {
    std::cout << Mod(12, 5) << std::endl; // 2
    std::cout << Mod(1.75, 1.5) << std::endl; // 0.25
}
**/

template <class T> requires std::is_integral_v<T>
T Mod(T x, T y) {
    return x % y;
}

template <class T> requires std::is_floating_point_v<T>
T Mod(T x, T y) {
    return fmod(x, y);
}

/**
// 以下、C++20の仕様ではOKの書き方だが、処理系がまだ対応していない。
template <integral T> // std::integral コンセプト
T Mod2(T x, T y) {
    return x % y;
}

template <floating_point T> // std::floating_point コンセプト
T Mod2(T x, T y) {
    return fmod(x, y);
}
**/

// 「同じ型同士の + 演算が定義されている型」のコンセプト
template <class T>
concept Addable = requires (T x) { x + x; };

template <Addable T>
auto Add3(T a, T b, T c) {
    return a + b + c;
}

// 「.size() メンバ関数を持つ型」のコンセプト
template <class T>
concept HasMemberFunctionSize = requires (T x) { x.size(); };

template <HasMemberFunctionSize T>
void ShowSize(const T& c) {
    std::cout << c.size() << std::endl;
}

int main() {
    std::cout << Mod(12, 5) << std::endl; // 2
    std::cout << Mod(1.75, 1.5) << std::endl; // 0.25
    // std::cout << Mod2(12, 5) << std::endl; // 2
    // std::cout << Mod2(1.75, 1.5) << std::endl; // 0.25

    std::cout << Add3(1, 2, 3) << std::endl; // 6
    std::cout << Add3("aa"s, "bb"s, "cc"s) << std::endl; // aabbcc
    ShowSize("abcde"s); // 5
}
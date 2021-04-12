#include <iostream>
#include <type_traits>

/**
// 以下のコードはエラーとなる。
template <class T>
auto GetValue(T t) {
    if (std::is_pointer_v<T>) {
        // T = int のとき、*t ができず実体化に失敗する。
        return *t;
    } else {
        // T = int* のとき、全ての return の型が一致せず、実体化に失敗する。
        return t;
    }
}

int main() {
    int a = 100;
    int* p = &a;
    std::cout << GetValue(a) << std::endl; // コンパイルエラー
    std::cout << GetValue(p) << std::endl; // コンパイルエラー
}
**/

template <class T>
auto GetValue(T t) {
    if constexpr (std::is_pointer_v<T>) {
        // T = int のときは実体化から除外される。
        return *t;
    } else {
        // T = int* のときは実体化から除外される。
        return t;
    }
}

int main() {
    int a = 100;
    int* p = &a;

    std::cout << GetValue(a) << std::endl; // OK: 100
    std::cout << GetValue(p) << std::endl; // OK: 100
}
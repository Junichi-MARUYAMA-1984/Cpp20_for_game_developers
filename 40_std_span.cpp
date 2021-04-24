#include <iostream>
#include <vector>
#include <span>

/**
// C言語からの伝統的なメモリ引数のやり取り方法
void Print(const int* arr, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    int a[] = { 1, 2, 3, 4, 5 };

    Print(v.data(), v.size()); // 1 2 3 4 5
    Print(a, std::size(a)); // 1 2 3 4 5
}
**/

// std::spanを用いたメモリ引数のやり取り方法
void Print(std::span<const int> s) {
    for (const auto& x : s) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    int a[] = { 1, 2, 3, 4, 5 };

    // std::vectorをstd::spanに変換
    Print(std::span{v}); // 1 2 3 4 5

    // 配列をstd::spanに変換（長さは配列から静的に決定される）
    Print(std::span{a}); // 1 2 3 4 5

    // subspanで部分列を作る
    Print(std::span{v}.subspan(1, 3)); // 2 3 4

    // ポインタと要素数を指定して構築
    Print(std::span<int>{a, 3}); // 1 2 3
}
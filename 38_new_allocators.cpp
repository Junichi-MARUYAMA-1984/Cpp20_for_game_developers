#include <vector>
#include <memory_resource>
#include <iostream>

void F(const std::pmr::vector<int>&) {}

int main() {
    std::pmr::vector<int> v1; // デフォルトのmemory_resourceを使用。

    MyMemoryResource myMR; // ユーザが実装したmemory_resourceを使用。
    std::pmr::vector<int> v2{ v1, &myMR }; // v1もv2も同じ型。

    F(v1); // OK
    F(v2); // OK
}
#include <vector>
#include <algorithm>
#include <iostream>

/**
int main() {
    std::vector v = { 1, 2, 3, 4, 5 };

    // 左へ1ローテートすると、{ 2, 3, 4, 5, 1 }になる。
    std::rotate(v.begin(), v.begin() + 1, v.end());

    // { 2, 3, 4, 5, 6 }になる
    v.back() = 6;
}
**/

int main() {
    std::vector v = { 1, 2, 3, 4, 5 };

    // 左へ1シフトすると、{ 2, 3, 4, 5, (未規定) }になる。
    std::shift_left(v.begin(), v.end(), 1);

    // {2, 3, 4, 5, 6}になる
    v.back() = 6;

    for (auto e : v) {
        std::cout << e << std::endl;
    }
}
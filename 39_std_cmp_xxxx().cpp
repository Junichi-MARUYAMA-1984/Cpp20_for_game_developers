#include <iostream>
#include <cstdint>
#include <utility>

struct Image {
    uint32_t width, height;
};

auto F(Image& img) {
    // 符号有無が異なっても警告は出ない
    for (int x = 0; std::cmp_less(x, img.width); ++x) {
        // キャストの必要もない
        for (int y = 0; std::cmp_less(y, img.height); ++y) {
            // ...
        }
    }
}

int main() {
    std::cout << std::boolalpha;

    int s = -1;
    unsigned u = 0;

    std::cout << std::cmp_less(s, u) << std::endl; // true
    std::cout << std::cmp_less(-1, 0) << std::endl; // true
}
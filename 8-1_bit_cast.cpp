#include <iostream>
#include <cstdint>
#include <bit>
using namespace std;

int main() {
    constexpr float f = 0.5f;
    constexpr uint32_t u = bit_cast<uint32_t>(f);
    cout << u << endl; // 1056964608
}
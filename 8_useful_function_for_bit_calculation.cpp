#include <iostream>
#include <bit>
using namespace std;

int main() {
    cout << boolalpha;

    // 2 の累乗数か？
    cout << has_single_bit(512u) << endl; // true

    // 2 の累乗数に切り捨てる。
    cout << bit_floor(1023u) << endl; // 512

    // 2 の累乗数に切り上げる。
    cout << bit_ceil(1023u) << endl; // 1024

    // その数の表現に最低何ビット必要か？
    cout << bit_width(31u) << endl; // 5
    cout << bit_width(32u) << endl; // 6

    const uint16_t x = 0b0001'0110'1110'1111;

    // 左にビットローテートした値を返す。
    cout << rotl(x, 2) << endl; // 23484 (0b0101'1011'1011'1100)

    // 右にビットローテートした値を返す。
    cout << rotr(x, 2) << endl; // 50619 (0b1100'0101'1011'1011)

    // 最上位ビットから連続する 0 の個数
    cout << countl_zero(x) << endl; // 3

    // 最下位ビットから連続する 1 の個数
    cout << countr_one(x) << endl; // 4
    // 1になるビットの個数
    cout << popcount(x) << endl; // 10
}
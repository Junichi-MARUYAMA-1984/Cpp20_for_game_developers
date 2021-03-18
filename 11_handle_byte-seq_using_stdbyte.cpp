#include <cstddef>
#include <vector>
using namespace std;

int main() {
    byte a{ 0b1011'0101 };
    byte b{ 0x0A };
    vector<byte> data = { a, b, byte { 24u } };
    // OK
    data[0] &= byte { 1 };

    // OK
    data[2] = byte { 0x0A };
}
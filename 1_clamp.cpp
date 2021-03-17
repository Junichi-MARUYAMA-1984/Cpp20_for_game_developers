#include <iostream>
#include <algorithm>
using namespace std;

void Compress(int quality) {
    // qualityを 0 ~ 100 の範囲に収める
    quality = clamp(quality, 0, 100);
    cout << "quality: " << quality << '\n';
}

int main() {
    Compress(110);
    Compress(-50);
}
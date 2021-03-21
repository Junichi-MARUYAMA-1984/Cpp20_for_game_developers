#include <iostream>
using namespace std;

struct Float2 {
    float x, y;
    Float2(float x, float y) : x(x), y(y) {}
    [[nodiscard]] Float2 normalized() const; // 正規化した値を返す
};

int main() {
    Float2 v(1.0f, 1.0f);
    v.normalized(); // 戻り値を捨てているので警告される
}
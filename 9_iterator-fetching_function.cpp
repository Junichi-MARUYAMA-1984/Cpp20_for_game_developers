#include <vector>
#include <algorithm>
using namespace std;

template <class Container>
void F(Container& c) {
    size_t n = size(c);
    int64_t i = ssize(c); // サイズを符号付き整数型で得たい場合に便利。
    fill(begin(c), end(c), 0);
}

int main() {
    vector<int> v = { 1, 2, 3 };
    int a[4] = { 10, 20, 30, 40 };

    F(v); // OK
    F(a); // OK
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = { 1, 5, 3, 2, 4 };
    auto is_even = [](int n) { return n % 2 == 0; };
    
    auto b = ranges::count_if(v, is_even);
    cout << b << endl;

    int max = ranges::max(v);
    cout << max << endl;

    ranges::sort(v);
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;

    ranges::fill(v, 5);
    for (auto x : v) {
        cout << x << " ";
    }
}
#include <iostream>
#include <vector>
using namespace std;

// 三方比較演算子の利用
struct Date {
    int year, month, day;
    auto operator <=>(const Date&) const = default;
};

// vector の効率的な比較の例
template<typename T>
bool operator ==(const vector<T>& lhs, const vector<T>& rhs) {
    // サイズを先にチェックすることで比較をショートサーキット。
    const size_t size = lhs.size();
    if (size != rhs.size()) {
        return false;
    }

    for (size_t i = 0; i != size; ++i) {
        // ネストする比較においても <=> ではなく == を使う。
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }

    return true;
}

template<typename T>
bool operator !=(const vector<T>& lhs, const vector<T>& rhs) {
    return !(lhs == rhs);
}

int main() {
    cout << boolalpha;
    cout << (Date{ 2020, 12, 25 } == Date{ 2020, 12, 25 }) << endl;
    cout << (Date{ 2020, 12, 25 }  < Date{ 2020, 12, 25 }) << endl;
    cout << (Date{ 2020, 12, 25 } >= Date{ 2020, 12, 25 }) << endl;
    cout << endl;
    cout << (vector<int>{ 1, 2, 3 } == vector<int>{ 2, 3, 4}) << endl;
    cout << (vector<float>{ 1.2f, 2.4f, 3.6f } != vector<float>{ 1.1f, 2.2f, 3.3f }) << endl;
}
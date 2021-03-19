#include <iostream>
#include <cmath>
using namespace std;

// _deg リテラル演算子の定義
constexpr double operator"" _deg(long double deg) {
    return deg * (3.14159265358979323846 / 180.0);
}

// 文字列リテラルに対する _repeat リテラル演算子の定義
struct MyRepeatObj {
    const char* m_s;
    size_t m_len;
    constexpr MyRepeatObj(const char* s, size_t len) :
        m_s(s), m_len(len) {}
    string operator ()(int n) const {
        string s;
        for (int i = 0; i < n; ++i) {
            s.append(m_s, m_len);
        }
        return s;
    }
};

constexpr MyRepeatObj operator"" _repeat(const char* s, size_t len) {
    return MyRepeatObj{ s, len }; // operator()を持つオブジェクトを返す
}

int main() {
    cout << sin(89.5_deg) << endl; // 0.999962
    cout << "Hello"_repeat(3) << endl; // HelloHelloHello
    cout << "Goo"_repeat.m_len << endl; // 3
}
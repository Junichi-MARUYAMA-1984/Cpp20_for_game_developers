#include <vector>
#include <memory>
using namespace std;

struct S {
    vector<int> m_buffer;
    void work(unique_ptr<int> ptr, int n) {
        auto f = [
            &b = m_buffer, // 新しい参照変数 b でデータメンバを参照キャプチャ
            p = move(ptr), // 新しい変数 p を作ってムーブキャプチャ
            flag = (n > 3) // 新しい変数 flag で式の結果をキャプチャ
        ]() mutable { ... };
    }
}
#include <iostream>
#include <source_location>
using namespace std;

void MyFunc() {
    constexpr auto s = source_location::current(); // ここで情報を取得。
    cout << s.file_name() << endl; // ファイル名
    cout << s.line() << endl; // 行番号
    cout << s.column() << endl; // 列番号（何文字目か）
    cout << s.function_name() << endl; // 関数名
}

int main() {
    MyFunc();
}
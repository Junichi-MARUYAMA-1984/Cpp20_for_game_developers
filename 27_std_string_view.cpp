#include <string>
#include <string_view>
#include <iostream>

/**
void WriteLog(const std::string& s); // std::string型の参照を受け取る関数

int main() {
    WriteLog("Hello"); // 文字列リテラルを渡すと、std::string型の一時オブジェクトが作られる。
    const char* s1 = "Modern";
    WriteLog(s1); // const char*を渡しても、std::string型の一時オブジェクトが作られる。
    std::string s2 = "C++";
    WriteLog(s2); // std::string型を渡すと、意図通り参照渡しになる。
}
**/

void WriteLog(std::string_view s) { // 値渡しでOK
    std::cout << s.substr(0, 2) << std::endl; // 部分文字列もstring_viewで作成できるので効率的
}

int main() {
    WriteLog("Hello"); // 文字列リテラルでも、先頭ポインタと長さだけ渡される
    const char* s1 = "Modern";
    WriteLog(s1); // const char*でも、先頭ポインタと長さだけ渡される
    std::string s2 = "C++";
    WriteLog(s2); // std::string型でも、当然先頭ポインタと長さだけ渡される
}
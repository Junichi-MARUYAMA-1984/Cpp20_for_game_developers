#include <vector>
#include <array>
#include <string>
#include <tuple>
#include <mutex>

std::string operator"" s(const char* str, std::size_t length)
{
  return std::string(str, length);
}

// C++14
void F() {
    std::vector<int>               v = { 1, 2, 3 };
    std::array<double, 3>          a = { 0.1, 0.2, 0.3 };
    std::tuple<int, float, std::string> t = { 30, 0.5f, "hello"s };
    std::mutex m;
    std::lock_guard<std::mutex> lock(m);
}

// C++17
void G() {
    std::vector v = { 1, 2, 3 };
    std::array  a = { 0.1, 0.2, 0.3 };
    std::tuple  t = {30, 0.5f, "hello"s };
    std::mutex m;
    std::lock_guard lock(m);
}

int main() {
    // テンプレート引数を省略しない場合
    std::tuple<int, float, std::string> t1 = { 30, 0.5f, "hello"s };

    // 変数の型を推論させ、代わりに生成関数を使う場合
    auto t2 = std::make_tuple(30, 0.5f, "hello"s);

    // テンプレート引数を省略する場合
    std::tuple t3 = { 30, 0.5f, "hello"s };
}
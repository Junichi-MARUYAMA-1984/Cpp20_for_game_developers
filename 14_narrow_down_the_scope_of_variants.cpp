#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> ss = { "aa", "bb", "cc" };
    for (size_t i = 0; const auto& s : ss) {
        cout << i++ << ": " << s << endl; // i のスコープはループ内のみ
    }
}
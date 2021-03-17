#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> table = {{ "one", 1 }, { "two", 2 }};

    if (table.contains("one")) {
        cout << "oneというキーを持つ要素が存在します。" << endl;
    }

    if (auto it = table.find("one"); it != table.end()) {
        cout << "'one' : " << it->second << endl;
    }
}
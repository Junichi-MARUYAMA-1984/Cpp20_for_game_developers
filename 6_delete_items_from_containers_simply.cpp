#include <vector>
#include <list>
#include <string>
#include <unordered_map>
using namespace std;

auto LessThan10 = [](int n){ return n < 10; };

int main() {
    vector<int> v = { 1, 2, 5, 10, 20 };
    list<int> li = { 1, 2, 5, 10, 20 };
    unordered_map<string, int> m = {{ "one", 1 }, { "ten", 10 }};

    // vectorの要素を削除
    // v.erase(remove_if(v.begin(), v.end(), LessThan10), v.end());
    erase_if(v, LessThan10);

    // listの要素を削除
    // li.remove_if(LessThan10);
    erase_if(li, LessThan10);

    // unordered_mapの要素を削除
    // for (auto it = m.begin(); it != m.end(); ) {
    //     if (LessThan10(it->second)) {
    //         it = m.erase(it);
    //     } else {
    //         ++it;
    //     }
    // }
    erase_if(m, [](const auto& p) {return LessThan10(p.second); });
}
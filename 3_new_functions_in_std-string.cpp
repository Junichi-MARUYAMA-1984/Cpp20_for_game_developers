#include <iostream>
#include <string>
using namespace std;

int main() {
    string path = "test.png";
    cout << boolalpha;
    cout << path.ends_with(".png") << endl; // true
    cout << path.ends_with(".jpg") << endl; // false

    string url = "https://cpprefjp.github.io/";
    cout << url.starts_with("https://") << endl; // true

    string s = "C++20";
    cout << s.starts_with('C') << endl; // true
    cout << s.ends_with('+') << endl; // false
}
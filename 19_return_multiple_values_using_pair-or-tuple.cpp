#include <iostream>
#include <string>
#include <utility>
#include <tuple>
using namespace std;

pair<double, double> GetTwo() {
    // return make_pair(35.2, 136.9); // C++14まで
    return{ 35.2, 136.9 };
}

tuple<double, double, string> GetThree() {
    // return make_tuple(35.2, 136.9, string("Nagoya")); // C++14まで
    return{ 35.2, 136.9, "Nagoya" };
}

int main() {
    auto[x, y] = GetTwo();
    cout << x << ", " << y << endl;

    auto[lat, lng, name] = GetThree();
    cout << lat << ", " << lng << ", " << name << endl;
}
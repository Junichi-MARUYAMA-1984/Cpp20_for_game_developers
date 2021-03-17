#include <iostream>
#include <numbers>
using namespace std;

int main() {
    using std::numbers::pi;
    using std::numbers::pi_v;
    cout << 2.0 * pi << endl;
    cout << pi_v<float> << endl;
}
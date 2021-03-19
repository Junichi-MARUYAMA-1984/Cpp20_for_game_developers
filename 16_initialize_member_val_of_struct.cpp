#include <iostream>
using namespace std;

struct D3D12_VIEWPOINT {
    float TopLeftX, TopLeftY, Width, Height, MinDepth, MaxDepth;
};

int main() {
    const D3D12_VIEWPOINT viewpoint = {
        .TopLeftX = 0.0f,
        .TopLeftY = 0.0f,
        .Width    = 1280.0f,
        .Height   = 720.0f,
        .MinDepth = 0.0f,
        .MaxDepth = 1.0f,
    };

    const D3D12_VIEWPOINT viewpoint_2 = {
        .Width    = 1280.0f,
        .Height   = 720.0f,
        .MaxDepth = 1.0f,
    };

    cout << viewpoint.Width << endl;
    cout << viewpoint_2.TopLeftX << endl;
}
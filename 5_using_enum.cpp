#include <iostream>
using namespace std;

enum class ImageFormat { BMP, PNG, JPEG, DDS };

Image Decode(ImageFormat format) {
    switch (format) {
        using enum ImageFormat;
        case BMP:  return DecodeBMP();
        case PNG:  return DecodePNG();
        case JPEG: return DecodeJPEG();
        case DDS:  return DecodeDDS();
        default: return{};
    }
}
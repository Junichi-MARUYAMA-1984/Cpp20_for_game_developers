#include <memory>

struct alignas(16) Float4 {
    float x, y, z, w;
};

// ポインタv1, v2の指すデータは16バイト境界にアライメント
Float4 Add1(const Float4* v1, const Float4* v2) {
    return{ (v1->x + v2->x), (v1->y + v2->y),
            (v1->z + v2->z), (v1->w + v2->w) };
}

// そのままでは、ポインタv1, v2の指すデータのアライメントは不明なので、
// std::assume_aligned<>()関数テンプレートでアライメントを指定する。
Float4 Add2(const float* v1, const float* v2) {
    // ポインタv1, v2の指すデータが
    // 16バイト境界にアライメントされていると見なす。
    v1 = std::assume_aligned<16>(v1);
    v2 = std::assume_aligned<16>(v2);
    
    return{ (v1[0] + v2[0]), (v1[1] + v2[1]),
            (v1[2] + v2[2]), (v1[3] + v2[3]) };
}
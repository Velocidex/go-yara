#include <stdint.h>


// A fast approximate log2 function:
// https://github.com/etheory/fastapprox/blob/master/fastapprox/src/fastlog.h
// Having it here removes the need to link to the math library and
// reduces our depenencies while being good enough for entropy
// detection.
double log2 (double x)
 {
    union { float f; uint32_t i; } vx = { x };
    union { uint32_t i; float f; } mx = { (vx.i & 0x007FFFFF) | 0x3f000000 };
    float y = vx.i;
    y *= 1.1920928955078125e-7f;

    return y - 124.22551499f
        - 1.498030302f * mx.f
        - 1.72587999f / (0.3520887068f + mx.f);
}

#include "typedef.h"
// 函数功能:  *retv = a * b
// 输入:  a , b
// 输出:  *retv
#define METHOD 1
static void UF32_Mul_UF32(UF32 a, UF32 b, STR_UF64 *retv)
{

#if (METHOD == 0)
    UF16 mul_a = 0,mul_b = 0;
    STR_UF64 t;

    retv->high = 0;
    retv->low = 0;
    t.high = 0;
    t.low = 0;

    mul_a = (UF16)(a>>16);
    mul_b = (UF16)b;
    t.high = mul_a*mul_b;
    mul_a = (UF16)a;
    mul_b = (UF16)(b>>16);
    t.low = mul_a*mul_b;

    UF32_Add_UF32(t.high,t.low,retv);

    retv->high = (retv->high<<16) | ((retv->low >> 16 ) & 0x0000ffff);
    retv->low = (retv->low << 16 ) & 0xffff0000;

    mul_a = (UF16)a;
    mul_b = (UF16)b;
    t.low = mul_a*mul_b;

    mul_a = (UF16)(a>>16);
    mul_b = (UF16)(b>>16);
    t.high = mul_a*mul_b;

    UF64_Add_UF64(retv,&t);
    retv->high = ( a > ( 0xffffffff - b)) ? 1 : 0;

#elif (METHOD == 1)
    UF16 ah,bh;
    STR_UF64 t;

    ah = a >> 16;
    bh = b >> 16;
    a &= 0xffff;
    b &= 0xffff;

    retv->high = ah*bh;
    retv->low  = a*b;
    UF32_Add_UF32(a*bh, b*ah, &t);

    t.high = (t.high << 16) | (t.low >> 16);
    t.low <<= 16;
    UF64_Add_UF64(retv, &t);
#endif
}

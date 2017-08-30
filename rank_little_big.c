#include "typedef.h"

// 函数功能: 输入2个整数x,y,由小到大输出。并放入x.y
// 输入:    x,y
static void Rank2_Little_To_Big(UF32 *x,UF32 *y)
{
    if(*x > *y)
    {
    #if 0
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
    #elif 1
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    #endif
    }
}

// 函数功能: 输入三个整数x,y,z，请把这三个数由小到大输出。并放入x.y,z
// 输入:    x,y,z
static void Rank3_Little_To_Big(UF32 *x,UF32 *y,UF32 *z)
{
    Rank2_Little_To_Big(x,y);
    Rank2_Little_To_Big(x,z);
    Rank2_Little_To_Big(y,z);
}

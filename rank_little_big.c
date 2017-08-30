#include "typedef.h"

// ��������: ����2������x,y,��С���������������x.y
// ����:    x,y
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

// ��������: ������������x,y,z���������������С���������������x.y,z
// ����:    x,y,z
static void Rank3_Little_To_Big(UF32 *x,UF32 *y,UF32 *z)
{
    Rank2_Little_To_Big(x,y);
    Rank2_Little_To_Big(x,z);
    Rank2_Little_To_Big(y,z);
}

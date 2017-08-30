#include "typedef.h"


//函数功能 :判断该数是不是素数，是返回1，不是返回0
static Boolean IsPrime(UF16 n)
{
    UF16 factor;
#if 0
    for(factor = 2;factor < n;factor++)
    {
        if(n % factor == 0)
        {
            return 0;
        }
    }
    return 1;
#elif 1
    for (factor = 2; (factor * factor) < (n + 1); ++factor)
    {
        if (!(n % factor))
        {
            return 0;
        }
    }
    return 1;
#endif
}

//求n之内的素数　,结果顺序放在rst中，返回个数
static UF32 Prime_Number(UF32 *rst,UF32 n)
{
    UF32 i;
    UF32 *p;

    p = rst;

    if(n < 2)
    {
        return 0;
    }
    *p++ = 2;
    for(i = 3;i < n;i += 2) //加2去除偶数的判断
    {
        if(IsPrime(i) == 1)
        {
            *p++ = i;
        }
    }
    return p-rst;
}
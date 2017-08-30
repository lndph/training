#include "typedef.h"


//�������� :�жϸ����ǲ����������Ƿ���1�����Ƿ���0
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

//��n֮�ڵ�������,���˳�����rst�У����ظ���
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
    for(i = 3;i < n;i += 2) //��2ȥ��ż�����ж�
    {
        if(IsPrime(i) == 1)
        {
            *p++ = i;
        }
    }
    return p-rst;
}
#include "typedef.h"
#include <stdio.h>
//题目：一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2＋3.编程
//找出1000以内的所有完数。
static void Perfect_Number(void)
{
    UF16 n;
    UF16 factor;
    UF16 sum;

    for(n = 1;n < 1000;n++)
    {
        sum = 0;
        for(factor = 1;factor < n;factor++)
        {
            if(n % factor == 0)
            {
                sum += factor;
            }
        }
        if ( sum == n)
        {
            printf("%d\n",n);
        }
    }
}

#include "typedef.h"

/*
函数功能:计算圆周率pi的值
pi/2 = 1 + 1/3 + 1/3 * 2/5 + ..
计算π的近似值，当某一项的值小于10-5时，认为达到精度要求
*/
static float Count_Pi()
{
    float sum = 0,t = 1;
    float a = 1,b = 3; //    a/b

    while(t > 0.0000001)
    {
        t *= a / b;
        sum += t;
        a += 1;
        b += 2;
    }
    return (sum + 1) * 2;
}

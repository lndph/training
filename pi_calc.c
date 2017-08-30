#include "typedef.h"

/*
��������:����Բ����pi��ֵ
pi/2 = 1 + 1/3 + 1/3 * 2/5 + ..
����еĽ���ֵ����ĳһ���ֵС��10-5ʱ����Ϊ�ﵽ����Ҫ��
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

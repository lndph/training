#include "typedef.h"
#include <stdio.h>
//��Ŀ��һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ��������������6=1��2��3.���
//�ҳ�1000���ڵ�����������
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

#include "typedef.h"


//С�����λ����Ϊ  : ȡ����ռ�����İٷֱȣ���ֻ�����"���������İٷֱ�"�ճ�һ��������
//#define Round       0               // 0��1��, ȫ��λ
//#define Round       1               // 1��2��
//#define Round       2               // 2��3��
//#define Round       3               // 3��4��
#define Round       4               // 4��5��
//#define Round       5               // 5��6��
//#define Round       6               // 6��7��
//#define Round       7               // 7��8��
//#define Round       8               // 8��9��
//#define Round       9               // 9��10��, ȫ��
// ��������:  *a /= b
// ����:  *a , b
// ���:  *a
static void UF64_Div_UF16(STR_UF64 *a, UF16 b)
{
   UF32 dived;

  /*   dived = a->high;

    a->high = dived / b;

    dived = ((dived % b) << 16) | (a->low >> 16);

    a->low = ((dived / b) << 16);

    dived = ((dived % b) << 16) | (a->low & 0xffff);
    a->low |= (dived / b);*/

    STR_UF64 tmp;

    tmp.high = 0;
    tmp.low = ((9 - Round) * b) / 10;
    UF64_Add_UF64(&tmp, a);

    a->high = tmp.high / b;
    dived = ((tmp.high % b) << 16) | (tmp.low >> 16);
    a->low = (dived / b) << 16;
    dived = ((dived % b) << 16) | (tmp.low & 0xffff);
    a->low |= dived / b;
}


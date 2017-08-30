#include "typedef.h"


//小数点进位规则为  : 取余数占除数的百分比，故只需加上"其允许误差的百分比"凑成一个除数，
//#define Round       0               // 0舍1入, 全进位
//#define Round       1               // 1舍2入
//#define Round       2               // 2舍3入
//#define Round       3               // 3舍4入
#define Round       4               // 4舍5入
//#define Round       5               // 5舍6入
//#define Round       6               // 6舍7入
//#define Round       7               // 7舍8入
//#define Round       8               // 8舍9入
//#define Round       9               // 9舍10入, 全舍
// 函数功能:  *a /= b
// 输入:  *a , b
// 输出:  *a
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


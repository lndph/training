#include "typedef.h"

#define METHOD  1
// 函数功能:    *retv = a + b;
// 输入:  a , b
// 输出:  *rst
static void UF32_Add_UF32(UF32 a, UF32 b, STR_UF64 *retv)
{
    retv->low = a + b;
    //a + b > 0xffffffff就会产生进位位，对式子进行变形可得
    //0xffffffff - b = ~b
#if (METHOD == 0)
    retv->high = ( a > ( 0xffffffff - b)) ? 1 : 0;
#elif (METHOD == 1)
    retv->high = ( b > ( 0xffffffff - a)) ? 1 : 0;
#elif (METHOD == 2)
    retv->high = ( a > (~b)) ? 1 : 0;
#elif (METHOD == 3)
    retv->high = ( b > (~a)) ? 1 : 0;
#endif
}

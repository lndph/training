#include "typedef.h"

// ��������:  *a += *b;
// ����:  *a , *b
// ���:  *a
static void UF64_Add_UF64(STR_UF64 *a, STR_UF64 const *b)
{
    UF32 h;

    h = a->high + b->high;
    UF32_Add_UF32(a->low,b->low,a);
    a->high += h;
}


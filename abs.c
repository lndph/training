#include "typedef.h"

#if 0
//取绝对值
static UF32 abs(SF32 a)
{
  return a < 0 ? -a : a;
}
#else
//采用宏定义可减少函数开销，需注意参数没有副作用 例如 ++
#define abs(a) ((a) < 0 ? (-a) : (a))
#endif

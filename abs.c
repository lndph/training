#include "typedef.h"

#if 0
//ȡ����ֵ
static UF32 abs(SF32 a)
{
  return a < 0 ? -a : a;
}
#else
//���ú궨��ɼ��ٺ�����������ע�����û�и����� ���� ++
#define abs(a) ((a) < 0 ? (-a) : (a))
#endif

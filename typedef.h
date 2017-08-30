#ifndef __TYPEDEF_H__
    #define __TYPEDEF_H__

    typedef char                String;       // �ַ�����
    typedef unsigned int        Boolean;      // ������

    typedef unsigned char       UF08;         // �޷���  8 λ
    typedef unsigned short int  UF16;         // �޷��� 16 λ
    typedef unsigned long int   UF32;         // �޷��� 32 λ

    typedef signed char         SF08;         // ������  8 λ
    typedef signed short int    SF16;         // ������ 16 λ
    typedef signed long int     SF32;         // ������ 32 λ

    typedef unsigned int        UA08;         // �޷��� ����  8 λ
    typedef unsigned int        UA16;         // �޷��� ���� 16 λ
    typedef unsigned long       UA32;         // �޷��� ���� 32 λ

    typedef signed char         SA08;         // ������ ����  8 λ
    typedef signed int          SA16;         // ������ ���� 16 λ
    typedef signed long         SA32;         // ������ ���� 32 λ

    typedef struct
    {
        UF32   high;
        UF32   low;
    } STR_UF64;

    typedef struct
    {
        UA32         year;           // ��(0000~65535)
        UA08         month;          // ��(1~12)
        UA08         day;            // ��(1~31)
    } STR_DATE;

#endif

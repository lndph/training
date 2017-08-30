#ifndef __TYPEDEF_H__
    #define __TYPEDEF_H__

    typedef char                String;       // 字符串型
    typedef unsigned int        Boolean;      // 布尔型

    typedef unsigned char       UF08;         // 无符号  8 位
    typedef unsigned short int  UF16;         // 无符号 16 位
    typedef unsigned long int   UF32;         // 无符号 32 位

    typedef signed char         SF08;         // 带符号  8 位
    typedef signed short int    SF16;         // 带符号 16 位
    typedef signed long int     SF32;         // 带符号 32 位

    typedef unsigned int        UA08;         // 无符号 至少  8 位
    typedef unsigned int        UA16;         // 无符号 至少 16 位
    typedef unsigned long       UA32;         // 无符号 至少 32 位

    typedef signed char         SA08;         // 带符号 至少  8 位
    typedef signed int          SA16;         // 带符号 至少 16 位
    typedef signed long         SA32;         // 带符号 至少 32 位

    typedef struct
    {
        UF32   high;
        UF32   low;
    } STR_UF64;

    typedef struct
    {
        UA32         year;           // 年(0000~65535)
        UA08         month;          // 月(1~12)
        UA08         day;            // 日(1~31)
    } STR_DATE;

#endif

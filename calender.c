#include "typedef.h"
#include <stdio.h>

static const UF16 daytbl1[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
static const UF16 daytbl2[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
// 函数功能: 判断闰年
// 输入    : year : 年份
// 输出    : 0 : 平年
//           1 : 闰年
static Boolean IsLeapYear(UA32 year)
{
    return ((year % 4) != 0 || ( (year % 100) == 0 && (year % 400) != 0)) ? 0 : 1 ;
}

//计算日期天数，直接计算当前日期中离基准日期，年份过了多少天，当前月离本年第一天过了多少天，再加上天数

static UF32 GetDateDay(STR_DATE *src)
{
    UA32 y;
    UF16 const *mtbl;

    mtbl = (IsLeapYear(src->year)) ? daytbl2 : daytbl1;
    y = src->year -1;

    return ( y * 365L ) + ( y / 4 ) - ( y / 100 ) + ( y / 400 ) + mtbl[src->month - 1] + (src->day - 1);
}
#define CYC_4_DAYS      1461L
#define CYC_100_DAYS    36524L
#define CYC_400_DAYS    146097L

static void DayToDate(STR_DATE *dest,UF32 days)
{
    UF16 year_day;
    UF32 i;
    UF08 mon_day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    dest->year = 1;
    dest->month = 1;
    dest->day = 1;

    dest->year += (days/CYC_400_DAYS)*400;
    days = (days%CYC_400_DAYS);

    if ( days / CYC_100_DAYS == 4)
    {
        dest->year += 3*100;
        days = CYC_100_DAYS;
    }
    else
    {
        dest->year += (days/CYC_100_DAYS)*100;
        days = (days%CYC_100_DAYS);
    }

    dest->year += (days/CYC_4_DAYS)*4;
    days = (days%CYC_4_DAYS);

    //底下while循环为判断
    while(days > ((UF32)(year_day = (IsLeapYear(dest->year) ? 366 : 365))))
    {
        days -= year_day;
        dest->year++;
    }

    mon_day[1] = IsLeapYear(dest->year) ? 29 : 28;

    for(i = 0;(UF08)days >= mon_day[i] && i < 11;i++)
    {
        days -= mon_day[i];
        dest->month++;
    }
    dest->day += (UF08)days;
}
/*
*输入一个时间:年月，输出这月的日历

*/

const char *week[] = {"Mon  ","Tues ","Wed  ","Thur ","Fri  ","Sat  ","Sun  "};

void Calender_Mon(UA32 y,UA08 m)
{
    UF08 mon_day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    UF32 days;
    UF08 i;
    UF08 weekday;
    STR_DATE src;

    src.year = y;
    src.month = m;
    src.day = 1;
    days = GetDateDay(&src); //求出当前年距离1年1月1日的时间

    mon_day[1] = (IsLeapYear(src.year)) ? 29 : 28;

  //  printf("%d-%d\r\n",src.year,src.month);
    for(i = 0;i < 7; i++)
    {
        printf("%s",*(week+i));
    }
    printf("\n");
    weekday = days%7;

    for(i = 0;i < weekday; i++)
    {
        printf("     ");
    }
    printf("01   ");

    for(i = 1;i < mon_day[src.month - 1]; i++)
    {
        if((weekday = (weekday + 1) % 7) == 0)
        {
            printf("\n");
        }
        printf("%.2d   ",i+1);
    }
    printf("\n");
}
/*
*输入年，打印出日历
*/
void Calender_Year(UA32 y)
{
    UA08 m;

    for(m = 1;m < 13;m++ )
    {
        Calender_Mon(y,m);
    }
}
// 函数功能: 计算两个日期的差值 dt1 - dt2
// 输入    : date1: 日期1
//           date2: 日期2
// 输出    : date1 - date2
static SA32 Date_Sub_Date(STR_DATE *date1, STR_DATE *date2)
{
    return (SA32)(GetDateDay(date1) - GetDateDay(date2));
}
// 函数功能: 已知源日期src,目标日期与源日期相差的天数days,求目标日期dest = src + hex
// 输入:    src  : 源日期
//          days : 目标日期与源日期相差的天数
// 输出:    dest : 目标日期
static void TranDateHexToDate(STR_DATE *dest, STR_DATE *src, SA32 days)
{
    DayToDate(dest,(UA32)((SA32)GetDateDay(src) + days));
}

// 函数功能: 已知源日期date,判断这一天是这一年的第几天？
// 输入:    date  : 源日期
// 输出:    days : 判断这一天是这一年的第几天
static SA32 Date_Cal_Dday(STR_DATE *date)
{
    UF16 const *mtbl;

    mtbl = (IsLeapYear(date->year)) ? daytbl2 : daytbl1;
    return mtbl[date->month - 1] + date->day;
}

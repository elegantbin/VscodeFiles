#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//输入一个日期并判断这一天是这一年中的第几天

//判断是不是闰年
bool justify_run(int year){

    if(year%400 == 0) return true;
    if(year%4 == 0 && year%100 != 0)  return true;
    return false;
}

int main(){
    int year, month, day;
    printf("please input the date:\n");
    scanf("%d-%d-%d",&year,&month, &day);

    int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(justify_run(year))    month_day[1] = 29;

    int total_day = 0;
    for(int i = 0; i<month-1; i++){
        total_day += month_day[i]; 
    }
    total_day += day;
    printf("it's the %dth day in a year\n",total_day);
    return 0;
}
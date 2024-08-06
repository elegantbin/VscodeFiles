#include <stdio.h>
//计算y = x^2 与 x = a和x轴之间围成的面积

//近似计算
float cal_Area_dive(float a){
    float area_sum = 0;
    for(float i = 0; i < a; i += 0.001){
        area_sum += 0.001*i*i;
    }
    return area_sum;
}

//积分公式计算
float cal_Area_integral(float a){

    return (1.0/3.0)*a*a*a;
}

int main(){
    float a;
    printf("please input the a:\n");
    scanf("%f", &a);

    float area_sum1 = cal_Area_dive(a);
    float area_sum2 = cal_Area_integral(a);

    printf("the area1 is:%f\n",area_sum1);
    printf("the area1 is:%f\n",area_sum2);

    return 0;
}
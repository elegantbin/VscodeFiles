#include <stdio.h>
#include <stdlib.h>
//冒泡排序
void bubble_sort(int *array, int* size){
    for(int i = 0; i < *size-1; i++){
        int isSorted = 1;
        for(int j = 0; j < *size-1-i; j++){
            if(array[j] > array[j+1]){//如果这个数比下一个数更大那么交换位置
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted) break;//如果一轮下来没有交换顺序，说明已经排好了顺序
    }
}

//二分法找数
int mid_search(int* array,int size,int num){
    int l = 0;
    int r = size -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(array[mid] > num){
            r = mid-1;//注意边界的变化
        }else if(array[mid] < num){
            l = mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int arraySize;
    printf("plaese intput the size of the array :\n");
    scanf("%d", &arraySize);
    int* array = (int*)malloc(sizeof(int)*arraySize);
    printf("plaese intput the number in the array :\n");
    for(int i = 0; i < arraySize; i++){
        scanf("%d", &array[i]);
    }
    // int array[] = {1,5,9,2,45,3,99,111,666,888};
    // int arraySize  = sizeof(array)/sizeof(array[0]);
    bubble_sort(array, &arraySize);
    printf("the bubble sort is:\n");
    for(int i = 0; i < arraySize; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    int x = 0;
    printf("input the number you want to search in the array and will  return it's sub\n");
    scanf("%d", &x);
    int sub = mid_search(array, arraySize, x);
    if(sub != -1){
        printf("the sub in the array is: %d", sub);
    }else{
        printf("the num is not exist in the array\n");
    }
    return 0;
}
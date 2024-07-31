#include <stdio.h>  
#include <stdlib.h>  

typedef struct {  
    int a; // 舒适度  
    int b; // 价格  
} House;  

// 比较函数，用于按照价格排序房子  
int compare_houses(const void *a, const void *b) {  
    House *house1 = (House *)a;  
    House *house2 = (House *)b;  
    return house1->b - house2->b;  
}  

// 比较函数，最大堆使用，存储舒适度（使用负值实现最大堆）  
int max_heap_compare(const void *a, const void *b) {  
    return (*(int *)b - *(int *)a);  
}  

void push(int *heap, int *size, int value) {  
    heap[(*size)++] = value; // 添加新元素  
    int i = *size - 1;  
    while (i > 0) {  
        int parent = (i - 1) / 2;  
        if (heap[parent] < heap[i]) {  
            int temp = heap[parent];  
            heap[parent] = heap[i];  
            heap[i] = temp;  
            i = parent;  
        } else {  
            break;  
        }  
    }  
}  

int pop(int *heap, int *size) {  
    int top = heap[0];  
    heap[0] = heap[--(*size)];  
    int i = 0;  

    // 维持最大堆性质  
    while (1) {  
        int left = 2 * i + 1;  
        int right = 2 * i + 2;  
        int largest = i;  

        if (left < *size && heap[left] > heap[largest]) {  
            largest = left;  
        }  
        if (right < *size && heap[right] > heap[largest]) {  
            largest = right;  
        }  
        if (largest == i) {  
            break;  
        }  
        
        int temp = heap[i];  
        heap[i] = heap[largest];  
        heap[largest] = temp;  
        i = largest;  
    }  
    
    return top;  
}  

int main() {  
    int n, m;  
    scanf("%d %d", &n, &m);  

    int *friends_gold = (int *)malloc(n * sizeof(int));  
    House *houses = (House *)malloc(m * sizeof(House));  

    for (int i = 0; i < n; i++) {  
        scanf("%d", &friends_gold[i]);  
    }  

    for (int i = 0; i < m; i++) {  
        scanf("%d %d", &houses[i].a, &houses[i].b);  
    }  

    // 排序房子按价格  
    qsort(houses, m, sizeof(House), compare_houses);  
    
    // 排序朋友的金币  
    qsort(friends_gold, n, sizeof(int), compare_houses);  

    int max_comfort = 0;  
    int *max_heap = (int *)malloc(m * sizeof(int)); // 最大堆存储舒适度  
    int heap_size = 0;  
    int house_index = 0;  

    for (int i = 0; i < n; i++) {  
        // 将所有价格小于等于当前金币的房子都加入到可购买列表中  
        while (house_index < m && houses[house_index].b <= friends_gold[i]) {  
            push(max_heap, &heap_size, houses[house_index].a); // 将舒适度压入堆中  
            house_index++;  
        }  

        // 从最大堆中选择舒适度最高的房子  
        if (heap_size > 0) {  
            max_comfort += pop(max_heap, &heap_size); // 购买舒适度最高的房子  
        }  
    }  

    printf("%d\n", max_comfort);  

    free(friends_gold);  
    free(houses);  
    free(max_heap);  

    return 0;  
}
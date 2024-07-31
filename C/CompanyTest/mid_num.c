#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void* b){
    return (*(int*)a-*(int*)b);
}

int main() {
    int n;
    scanf("%d",&n);
    int *array = (int*)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        scanf("%d",&array[i]);
    }

    qsort(array, n, sizeof(int),compare);
    int mid;
    int k = 0;
    int turn = 0;
    if(n % 2 == 1){
        turn = 0;
        for(int i = 0; i < n; i++){
            if(turn == 0){
                mid = (n+1)/2 + k -1;
                turn = 1;
                k++;
            }else{
                mid = (n+1)/2 - k -1;
                turn = 0;
            }
            printf("%d ",array[mid]);
        }
    }else{
        turn = 0;
        for(int i = 0; i < n; i++){
            if(turn == 0){
                mid = n/2 - k -1;
                turn = 1;
                k++;
            }else{
                mid = n/2 + k -1;
                turn = 0;
            }
            printf("%d ",array[mid]);
        }
    }
    free(array);
    return 0;
}
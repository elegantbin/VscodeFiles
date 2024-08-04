#include <stdio.h>
#include <stdlib.h>

typedef void (*callback_func)(int);

void process_data(int data, callback_func func){
    printf("process data: %d\n", data);
    int process_data  = data * 2;
    func(process_data);
}

void process_cbfunc(int data){
    printf("the processed data: %d\n", data);
}

int main(){
    process_data(42, process_cbfunc);
    return 0;
}
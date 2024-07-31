
int Sum_n(int n){
    if( n > 1)
    return Sum_n(n-1)+n;
    return 1;
}
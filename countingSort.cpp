#include<iostream>
using namespace std;
void countingSort(int a[], int b[], int max, int num){
    int c[100];
    for(int i = 0 ; i <=max ; i++)
        c[i] = 0;
    for(int i = 0 ; i < num ; i++)
        c[a[i]] = c[a[i]]+1;
    for(int i = 1; i <=max ; i++)
        c[i] = c[i] + c[i-1];
    for(int i = num-1;i>=0;i--){
        b[c[a[i]]-1] = a[i];
        c[a[i]] = c[a[i]]-1;
    }
}
int main()
{
    int a[] = {1,3,33,41,2,45,83,51,91}, n = 0,b[100] ;
    n = sizeof(a) / sizeof(a[0]);
    int max = -10000;
    for(int i = 0 ; i < n ; i++)
        if(max < a[i])
            max = a[i];
    countingSort(a,b,max,n);
    for (int i = 0 ; i < n; i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
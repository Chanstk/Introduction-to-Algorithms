#include<iostream>
using namespace std;
void insertSort(int a[], int n, int iter){
    int key = 0, j = 0;
    for(int i = 1; i < n ; i++){
        key = a[i];
        j = i -1;
        while( j >= 0 && (a[j]%iter-a[j]%(iter/10))> (key%iter-key%(iter/10))){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void radixSort(int a[], int d, int n){
    int iter = 1;
    for(int i = 1;i <= d; i++){
            iter = iter*10;
            insertSort(a, n, iter);
    }
}
int main()
{
    int a[] = {532,232,324,856,444,852,343,123,573,923}, n = 0;
    n = sizeof(a) / sizeof(a[0]);
    radixSort(a, 3,n);
    for (int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
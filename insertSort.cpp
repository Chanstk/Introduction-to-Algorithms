#include<iostream>
using namespace std;
void insertSort(int a[], int n){
    int key = 0, j = 0;
    for(int i = 1; i < n ; i++){
        key = a[i];
        j = i -1;
        while( j >=0 && a[j]> key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main()
{
    int a[] = {22,10,2,4,1,4,6,4,2,3,9,33}, n = 0;
    n = sizeof(a) / sizeof(a[0]);
    insertSort(a, n);
    for (int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

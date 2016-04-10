#include<iostream>
using namespace std;
void merge(int a[], int s, int m, int e){
    int b[1000], c[1000],i = 0;
    for(i = 0 ; i <= m-s ; i++)
        b[i] = a[s+i];
    b[i] = 100000;
    for(i = 0 ; i <e-m; i++)
        c[i] = a[m+i+1];
    c[i] = 1000000;
    int j = 0;
    i = 0;
    for(int k = s; k<=e;k++){
        if(b[i]<=c[j]){
            a[k] = b[i];
            i++;
        }else{
            a[k] = c[j];
            j++;
        }
    }
}

void mergeSort(int a[], int s, int e){
    if (s < e ){
        int m = (s+e)/2;
        mergeSort(a, s, m);
        mergeSort(a, m+1, e);
        merge(a, s, m, e);
    }
}

int main()
{
    int a[] = {1,21,4,17,3,89,2,43,37,69}, n = 0;
    n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0,n-1);
    for (int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
#include<iostream>
using namespace std;
int quickSortPartition(int a[], int s, int e){
    int key = a[e];
    int i = s-1;
    int t = 0;
    for(int j = s; j<e;j++){
        if(a[j]<=key){
            i++;
            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
    t = a[i+1];
    a[i+1] = a[e];
    a[e] = t;
    return i + 1;
}
void quickSort(int a[], int s, int e){
    if(s<e){
        int m = quickSortPartition(a, s, e);
        quickSort(a, s, m-1);
        quickSort(a, m+1, e);
    }
}

int main()
{
    int a[] = {1,21,4,17,3,89,2,43,37,69};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0,n-1);
    for (int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
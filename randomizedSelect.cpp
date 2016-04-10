#include<iostream>
using namespace std;
int randomizedPartition(int a[], int s, int e){
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
int randomizedSelect(int a[], int s, int e, int i){
    if (s ==e )
        return a[s];
    int q = randomizedPartition(a, s, e);
    int k = q-s+1;
    if( k == i)
        return a[q];
    else if (i < k)
        return randomizedSelect(a,s,q-1,i);
    else
        return randomizedSelect(a,q+1,e, i-k);
}   
int main()
{
    int a[] = {22,10,2,4,1,4,6,4,2,3,9,33}, n = 0;
    n = sizeof(a) / sizeof(a[0]);
    cout<<randomizedSelect(a, 0,n-1,12);
    
    return 0;
}
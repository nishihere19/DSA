#include <bits/stdc++.h>
using namespace std;

void radixsort(int a[],int n){
    int getmax(int a[],int n);
    void countsort(int a[],int n,int pos);
    int max = getmax(a,n);
    int pos;
    for(pos=1;max/pos>0;pos*=10){
        countsort(a,n,pos);
    }
}
int getmax(int a[],int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(max<a[i]) max=a[i];
    }
    return max;
}

void countsort(int a[],int n,int pos){
    int count[10]={0};
    for(int i=0; i<n;i++){
        ++count[(a[i]/pos)%10];
    }
    for(int i=1;i<n;i++){
        count[i]=count[i]+count[i-1];
    }
    int b[n];
    for(int i=n-1;i>=0;i--){
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}

int main(){
    void radixsort(int a[],int n);
    void countsort(int a[],int n,int pos);
    int getmax(int a[],int n);
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    radixsort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}
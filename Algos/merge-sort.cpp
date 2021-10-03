#include <iostream>
using namespace std;

void merge(int *,int,int,int);
void merge(int *arr,int low,int high,int mid){

int i,j,k,a[100];
i=low;
j=mid+1;
k=low;
while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            a[k] = arr[i];
            k++;
            i++;
        }
        else  {
            a[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        a[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        a[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = a[i];
    }
}
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}


int main(){
    int n,array[100];
    cout<<"enter no to be sorted:";
    cin>>n;
    cout<<"enter numbers for sorting";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    merge_sort(array,0,n-1);
    cout<<"sorted array\n";
    for(int i=0;i<n;i++){
        cout<<array[i]<<'\t';
    }
}
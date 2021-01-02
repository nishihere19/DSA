#include<iostream>
using namespace std;
bool BinarySearch(int arr[], int n, int k){
    int s=0; // s is the index of the starting element
    int e=n-1; //e is the index of the last element
    while (s<=e){
        int mid=s+(e-s)/2;
        if (arr[mid]==k) return true;
        if (arr[mid]<k){
            s=mid+1;
        } else {
            e=mid-1;
        }
    }
    return false;
}
int main(){
    int n; cin>>n; //No. of elements in the array
    int arr[n];
    cout<<"Enter The elements of the array"<<endl;
    for (int i=0;i<n;i++) cin>>arr[i]; //Adding elements into the array
    //if elements are not sorted, uncomment the below statement
    //sort(arr,arr+n);
    cout<<"Enter the key value you want to search"<<endl;
    int search; cin>>search;
    if (BinarySearch(arr,n,search)) cout<<"Element is found"<<endl;
}
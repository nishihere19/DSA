#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void counting_sort(int a[],int n,int max)
{
    int freq[max+1]={0};
    for(int i=0;i<n;i++)
    {
        freq[a[i]]++;    //Updating the frequency of Array Elements
    }
    for(int i=1;i<max+1;i++)
    {
        freq[i]+=freq[i-1];
    }
    int b[n];
    for(int i=0;i<n;i++)
    {
       
        b[freq[a[i]]-1]=a[i];
        --freq[a[i]];
        
    }
    for(int i=0;i<n;i++)
    {
        a[i]=b[i];       //Copying Elements of output array in the original Array
    }
}
int main() {
    int n;
    cin>>n;   //Taking Input the Size of the Array
    int a[n];
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];     // Taking input the Array elements
        m=max(m,a[i]);    //Taking maximum of all the array Elements
    }
    counting_sort(a,n,m);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

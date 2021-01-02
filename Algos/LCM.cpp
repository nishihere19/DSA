//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


#include<iostream>

class Solution{
public:
    long long n;
    long long getSmallestDivNum(long long n){
        int i,flag=0,a[n],j;
        long long lcm=1;
        for(i=0;i<n;i++){
            a[i]=i+1;  //Adding elements 1 to n in the array.
            
        }
        for(i=1;i<n;i++){ // i+1 is the factor
            for(j=1;j<n;j++){  //j holds the numbers. (Starting from 1)
               if(a[j]%(i+1)==0){
                   a[j]/=(i+1);  //Dividing all the numbers 1 to n from a factor.
                   flag=1;     //If a number is divided, repeat the step again.
                   
               } 
            }
            if(flag==1){
                lcm*=(i+1);  //Lcm is updated.
                i--;
                flag=0;
            }
            
        }
       return lcm;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<< ob.getSmallestDivNum(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
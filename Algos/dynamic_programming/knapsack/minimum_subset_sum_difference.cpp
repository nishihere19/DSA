#include <bits/stdc++.h>

int static t [5][16];

void  isSum(int v[],int sum,int n){

    
    for (int i = 0; i <= sum; i++)
        t[0][i] = 0;
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;
 
 
    for(int i=1; i < n+1; i++){
        for(int j=1; j < sum +1; j++){
            if(v[i-1]<= j){
                t[i][j] = t[i-1][j - v[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]= t[i-1][j];
            }
        }
    }
}

int main(){
    int arr[] = {1,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum =0;
    for (int i=0 ; i < n;i++)sum+=arr[i];
    isSum(arr,sum,n );

    int minimum = sum;
    for(int i=0 ; i <=sum/2;i++){
        if(t[n][i]){
             minimum =  std::min(minimum,sum - 2 * i);
        }
    }
    std::cout<<minimum<<std::endl;
    return 0;
}

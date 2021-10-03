#include <bits/stdc++.h>
using namespace  std;

int static t[20][20];

int sumCount(int v[],int sum, int n){
    for(int i=0; i< sum+1; i++ ){
        t[0][i] = 0;
    }
    for(int i=0; i< n+1; i++ ){
        t[i][0] = 1;
    }
    for(int i=1; i< n+1; i++ ){
        for(int j=1; j< sum+1; j++ ){
            if(v[i-1]<= j){
                t[i][j] = t[i-1][j] + t[i-1][j-v[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    int v [] = {1,1,2,3};
    int size = sizeof(v)/sizeof(v[0]);
    int totalSum=0, diff=1;

    for(int i=0; i< size; i++){ totalSum += v[i];};
    
    int sum = (totalSum - diff) / 2;
    cout<<sumCount(v,sum,size)<<endl;
    return 0;
}
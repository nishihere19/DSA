#include <bits/stdc++.h>

int static t [5][16];

bool  isSum(int v[],int sum,int n){

    for (int i = 0; i <= n; i++)
        t[i][0] = true;
 
    for (int i = 1; i <= sum; i++)
        t[0][i] = false;
 
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
    return t[n][sum];
}

int main(){
    int v[] = {3,1,5,2};
    int n = sizeof(v)/sizeof(v[0]),sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=v[i];
    }
    if (sum % 2 == 0){
        bool isPresent = isSum(v,sum /2,n);
        isPresent ? std::cout<<true<<std::endl : std::cout<<false<<std::endl;
    }
    else
    {
        std::cout<<false<<std::endl;
    }
    return 0;
}
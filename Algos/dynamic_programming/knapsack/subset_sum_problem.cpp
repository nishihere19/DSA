#include <bits/stdc++.h>

int static t [5][16];
//recursion approach

bool isSum2(int v[],int sum,int n){
   if(sum == 0 ){
       return true;
   }
   else if( n==0){
       return false;
   }
   else if (v[n-1]<= sum)
   {
       bool temp1 = isSum2(v,sum - v[n-1],n-1);
       bool temp2 = isSum2(v,sum,n-1);

      if(temp1){
          return temp1;
      }else{
          return temp2;
      } 

   }
   else{
       return  isSum2(v,sum,n-1);
   }  
}

//TOP DOWN 

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
    int v[] = {3,4,5,2};
    int n = sizeof(v)/sizeof(v[0]);
    for (int i = 0; i <=15; i++)
    {
    int sum = i;
    int a = isSum(v,sum,n);
    int b = isSum2(v,sum,n);
        std::cout<<i<<" "<<b<<" "<<a<<std::endl;
    }
    return 0;
}
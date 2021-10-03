#include <bits/stdc++.h>
int count=0;
int w[5][11];
int CountisSum(int v[],int sum,int n){
    for (int i = 0; i <= sum; i++)
        w[0][i] = false;

     for (int i = 0; i <= n; i++)
        w[i][0] = true;
 
    
  for (int i =1; i <=n; i++)
  {
      for (int j = 1; j <=sum; j++)
      {
          if(v[i-1]<=j){
              w[i][j]= w[i-1][j] + w[i-1][j-v[i-1]];
          }
          else{
              w[i][j]= w[i-1][j] ;
          }
      }
      
  }
  return w[n][sum];
  
}


int main(){
    int v[] = {2,3,5,6,8,10};
    int n = sizeof(v)/sizeof(v[0]);
    std::cout<< CountisSum(v,10,n)<<std::endl;
    
    
    return 0;
}

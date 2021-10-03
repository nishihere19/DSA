#include <iostream>
#include <cstring>
//consider we have only 10 constraint
int static t [4][7];

int max(int a, int b) { return (a > b) ? a : b; };

//Memoization
// int knapsack(int wt[], int value[], int w, int n){
//     if(n==0 || w==0){
//         return 0;
//     }
//     if(t[n][w] != -1){
//         return t[n][w];
//     }

//     if(wt[n-1] > w){
//         t[n][w] = knapsack(wt,value,w,n-1);
//         return t[n][w];
//     }
//     else{
//         t[n][w] = max(value[n-1] + knapsack(wt,value,w-wt[n-1],n-1),knapsack(wt,value,w,n-1));
//         return t[n][w];
//     }
// };

//TOP DOWN
int knapsack(int wt[], int value[], int w, int n){
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if(i==0 || j== 0){
                t[i][j] = 0;
                std::cout<<t[i][j]<<" ";
            }
            else if(wt[i-1]<=j){
                t[i][j] = max(value[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
                 std::cout<<t[i][j]<<" ";
            }
            else{
                t[i][j] = t[i - 1][w];
                std::cout<<t[i][j]<<" ";
            }
        }
         std::cout<<std::endl;
    }
    return t[n][w];
}

int main(){
    int value[3] = {10,15,40};
    int wt[3] =    {1,2,3};
    // memset(t,-1,sizeof(t));
    std::cout<<knapsack(wt,value,6,3)<<std::endl;
    return 0;
}
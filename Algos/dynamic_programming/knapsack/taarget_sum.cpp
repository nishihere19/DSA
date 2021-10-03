#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        int max_length= 0;
        for(int i=0; i< strs.size(); i++){
            string s = strs[i];
                int one=0,zero=0;
                for(int j=0; j< s.length(); j++){
                if(s[j]== '1'){
                    one+=1;
                }else{
                    zero+=1;
                }
            }
            if(one <= n && zero <= m){
                max_length +=1; 
            }
        }
        return max_length;
        
    }


int main(){
    std::vector <string> str = {"10","0","1"};
    std::cout<<findMaxForm(str,1,1);
    return 0;
}
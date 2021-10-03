/* This Algorithm is based on arrays index matching, it matches the each element with index and then assigned that elemet to that index in this
way every element got sorted in asecending order */

#include<iostream>
using namespace std;
int main(){
int i,j,n,A[100]={0};
cout<<"Enter Size Of the Array: ";
cin>>n;
int B[n];
cout<<"Enter elements: ";
for(i=0;i<n;i++){
cin>>B[i]; }
for(i=0;i<n;i++){
    for(j=0;j<=100;j++){
        if(B[i]==j){
            A[j]=B[i];
            break;
        }
    }
}
for(i=0;i<100;i++){
    if(A[i]!=0){  /* the indexes which were not assigned with element that were assigned with 0, so to not print 0 and print only element for that */
cout<<A[i]<<" "; }
}
return 0;
}

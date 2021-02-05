#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int i, j, low=0, mid=0, high=n-1, unk=1, a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    while(unk-high!=1&&unk!=n){
        cout<<unk;
        if(a[unk]==0){
            int temp=a[unk];
            a[unk]=a[low];
            a[low]=temp;
            low+=1;
            if(mid<low) mid+=1;
            unk+=1;
        }
        else if(a[unk]==1){
            if(mid==low) mid+=1;
            int temp=a[unk];
            a[unk]=a[mid];
            a[mid]=temp;
            mid+=1;
            unk+=1;
        }
        else if(a[unk]==2){
            int temp=a[unk];
            a[unk]=a[high];
            a[high]=temp;
            high-=1;
        }

    }
    for(i=0;i<n;i++) cout<<a[i]<<endl;
    return 0;
}
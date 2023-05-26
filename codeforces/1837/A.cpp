#include <bits/stdc++.h>
using namespace std;
int t,x,k;
int main(){
    cin>>t;
    while(t--) {
        cin>>x>>k;
        if(x%k==0) {
            printf("2\n1 %d\n",x-1);
        }else{
            printf("1\n%d\n",x);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        int tmp,ct=0,x,xi,y,yi;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            if(abs(tmp-i)%k!=0) {
                if(ct==0) x=tmp,xi=i,ct++;
                else if(ct==1) y=tmp,yi=i,ct++;
                else ct=100;
            }
        }
        if(ct==0) puts("0");
        else if(ct==2&&(x+y-xi-yi)%k==0) puts("1");
        else puts("-1");
    }
    return 0;
}
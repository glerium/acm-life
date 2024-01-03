#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int _,k,n,b[10];
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n>>k;
        rep(i,1,n) cin>>b[i];
        long long pro=1;
        rep(i,1,n) {
            pro*=b[i];
        }
        vector<int> v;
        if(2023%pro!=0) {
            cout<<"NO"<<endl;
            goto end;
        }else{
            cout<<"YES"<<endl;
            cout<<2023/pro<<' ';
            for(int i=1;i<k;i++) cout<<1<<' ';
            cout<<endl;
        }
end:    ;
    }
    return 0;
}
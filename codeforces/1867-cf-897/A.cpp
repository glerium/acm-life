#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
int t,n,rk[maxn];
struct Num {
    int x;
    int id;
    bool operator<(const Num& rhs)const{
        return x<rhs.x;
    }
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].x;
        for(int i=1;i<=n;i++) a[i].id=i;
        sort(a+1, a+1+n);
        for(int i=1;i<=n;i++) rk[a[i].id]=i;
        for(int i=1;i<=n;i++) cout<<n+1-rk[i]<<' ';
        cout<<endl;
    }
    return 0;
}
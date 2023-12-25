#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e5+10;
int t,n,k,d,a[maxn],v[maxn];
bool check() {
    for(int i=1;i<=n;i++) if(a[i]<i) return false;
    return true;
}
int count() {
    int ct=0;for(int i=1;i<=n;i++) ct+=a[i]==i;
    return ct;
}
signed main() {
    cin>>t;
    while(t--) {
        cin>>n>>k>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>v[i];
        long long ans=d/2-1+count();
        while(!check()) {
            
        }
    }
    return 0;
}
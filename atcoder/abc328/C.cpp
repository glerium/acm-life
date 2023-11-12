#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=3e5+10;
int n,q,f[maxn];
char s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>q>>(s+1);
    for(int i=1;i<=n;i++) {
        f[i]=f[i-1]+(s[i-1]==s[i]);
    }
    while(q--) {
        int l,r; cin>>l>>r;
        cout<<f[r]-f[l]<<endl;
    }
    return 0;
}
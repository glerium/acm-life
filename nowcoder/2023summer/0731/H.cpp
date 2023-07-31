#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,a[maxn],b[maxn],sz[maxn],f[maxn],f2[maxn],bk[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=m;i++) cin>>sz[i];
    for(int i=1;i<=m;i++) {
        int mx=f[1];
        for(int j=1;j<=n;j++) {
            f2[j]=mx;
            mx = max(mx,f[j]);
            
        }
        for(int j=1;j<=n;j++) f[j]=f2[j];
    }
}
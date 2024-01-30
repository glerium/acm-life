#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=2e5+10;
int n,a[maxn],l[maxn],r[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        l[i]=min(a[i],l[i-1]+1);
    }
    for(int i=n;i>=1;i--) {
        r[i]=min(a[i],r[i+1]+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,min(l[i],r[i]));
    cout<<ans<<endl;
    return 0;
}
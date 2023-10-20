#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int n,a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int even=0, odd=0;
    for(int i=1;i<=n;i++) {
        if(a[i]&1) odd++;
        else even++;
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=a[i];
    if(odd%2==0) cout<<ans<<endl;
    else {
        int mi = 1e5;
        for(int i=1;i<=n;i++) if(a[i]&1) mi=min(mi,a[i]);
        cout<<ans-mi<<endl;
    }
    return 0;
}
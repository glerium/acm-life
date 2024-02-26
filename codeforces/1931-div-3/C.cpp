#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=2e5+10;
int t,n,a[maxn];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    auto check = [=](int x) -> int {
        int l=0,r=0;
        for(int i=1;i<=n;i++) {
            if(a[i]!=x) break;
            l++;
        }
        for(int i=n;i>=1;i--) {
            if(a[i]!=x) break;
            r++;
        }
        return min(l+r,n);
    };
    cout<<n-max(check(a[1]),check(a[n]))<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) solve();
}
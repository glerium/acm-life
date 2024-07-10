#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int n,L,R;
string s;
auto check = [](int x) -> bool {
    string pre = s.substr(0, x);
    int ct = 0, pos = 0;
    while(ct < L) {
        for(int i=0,j=pos;i<x;i++) {
            
        }
        ct++;
        pos = idx + pre.size();
    }
    if(ct >= L) return true;
    else return false;
};
void solve() {
    cin >> n >> L >> R;
    cin >> s;
    int l=1,r=n,mid,ans=0;
    while(l <= r) {
        mid = (l+r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid+1;
        }else
            r = mid-1;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

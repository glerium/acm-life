#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int co = 0, ce = 0;
    rep(i,1,n) {
        int tmp; cin >> tmp;
        if(tmp % 2 == 0)
            ce++;
        else
            co++;
    }
    if(ce >= 1) {
        cout << 1 + co << endl;
    }else{
        cout << co - 1 << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f;
void solve() {
    int x,y,k; cin >> x >> y >> k;
    vector<int> y1,y2,f1,f2;
    for(int i=1;i*i<=x;i++) {
        if(x % i == 0) {
            y1.push_back(i);
            if(i*i!=x) {
                y1.push_back(x / i);
            }
        }
    }
    for(int i=1;i*i<=y;i++) {
        if(y % i == 0) {
            y2.push_back(i);
            if(i*i!=y) {
                y2.push_back(y / i);
            }
        }
    }
    sort(y1.begin(), y1.end());
    sort(y2.begin(), y2.end());
    rep(i,0,y1.size()-1) f1.push_back(114514);
    rep(i,0,y2.size()-1) f2.push_back(114514);
    f1[f1.size()-1] = f2[f2.size()-1] = 0;
    for(int i=y1.size()-1;i>=0;i--) {
        for(int j=y1.size()-1;j>i;j--) {
            if(y1[j] % y1[i] == 0 && y1[j] / y1[i] <= k) {
                f1[i] = min(f1[i], f1[j] + 1);
            }
        }
    }
    for(int i=y2.size()-1;i>=0;i--) {
        for(int j=y2.size()-1;j>i;j--) {
            if(y2[j] % y2[i] == 0 && y2[j] / y2[i] <= k) {
                f2[i] = min(f2[i], f2[j] + 1);
            }
        }
    }
    int ans = 114514;
    rep(i,0,y1.size()-1) {
        rep(j,0,y2.size()-1) {
            if(y1[i] == y2[j]) {
                ans = min(ans, f1[i] + f2[j]);
            }
        }
    }
    if(ans == 114514) cout << -1 << endl;
    else cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

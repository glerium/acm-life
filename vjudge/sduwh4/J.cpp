#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    map<int,int> mp;
    rep(i,1,n) {
        int x; cin >> x;
        mp[x]++;
    }
    n -= 2;
    int lim = sqrt(n) + 1;
    rep(i,1,lim) {
        if(n % i != 0) continue;
        if((i == n / i && mp[i] >= 2) || (i != n / i && mp.count(i) && mp.count(n / i))) {
            cout << i << ' ' << n / i << endl;
            return;
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

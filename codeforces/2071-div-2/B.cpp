#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
bool check(ll x) {
    ll aa = round(sqrt(x));
    if(aa * aa == x)
        return true;
    else return false;
}
void solve() {
    int n; cin >> n;
    priority_queue<int,vector<int>,greater<int>> q;
    rep(i,1,n) q.push(i);
    vector<int> v;
    ll ans = 0;
    rep(i,1,n) {
        vector<int> us;
        while(!q.empty() && check(ans + q.top())) {
            us.push_back(q.top());
            q.pop();
        }
        if(q.empty()) {
            cout << -1 << endl;
            goto end;
        }
        int tmp = q.top();
        ans += tmp;
        v.push_back(q.top());
        q.pop();
        for(auto j : us)
            q.push(j);
    }

    for(auto i : v)
        cout << i << ' ';
    cout << endl;
end:;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

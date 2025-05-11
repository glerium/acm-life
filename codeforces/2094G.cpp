#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    ll m=0, q; cin >> q;
    ll x = 0, y = 0;
    deque<ll> que, rque;
    while(q--) {
        int s; cin >> s;
        if(s == 1) {
            y += x - m * que.back();
            int last = que.back();
            que.pop_back();
            que.push_front(last);

            last = rque.front();
            rque.pop_front();
            rque.push_back(last);
        } else if(s == 2) {
            y = (m + 1) * x - y;
            swap(que, rque);
        } else {
            int k; cin >> k;
            que.push_back(k);
            rque.push_front(k);
            m++;
            x += k;
            y += m * k;
        }
        cout << y << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

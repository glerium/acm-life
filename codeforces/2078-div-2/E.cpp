#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int query(int x) {
    cout << x << endl;
    int ret; cin >> ret;
    return ret;
}
void answer(int x, int y) {
    cout << "!" << endl;
    int m; cin >> m;
    cout << (m | x) + (m | y) << endl;
}
void solve() {
    int x = 0, y = 0;
    int q1 = 0;
    for(int i=1;i<30;i+=2) {
        q1 |= 1 << i;
    }
    int r1 = query(q1);
    for(int i=1;i<30;i+=2) {
        if(r1 & (1 << i)) {
            x |= 1 << i;
        }
    }
    for(int i=2;i<=30;i+=2) {
        if(r1 & (1 << i)) {
            x |= 1 << (i - 1);
            y |= 1 << (i - 1);
        }
    }
    
    int q2 = 0;
    for(int i=0;i<30;i+=2) {
        q2 |= 1 << i;
    }
    int r2 = query(q2);
    for(int i=0;i<30;i+=2) {
        if(r2 & (1 << i)) {
            x |= 1 << i;
        }
    }
    for(int i=1;i<=30;i+=2) {
        if(r2 & (1 << i)) {
            x |= 1 << (i - 1);
            y |= 1 << (i - 1);
        }
    }
    answer(x, y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

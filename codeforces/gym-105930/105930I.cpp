#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll INF = 0x3f3f3f3f;
map<array<int,9>,int> mp;
void solve() {
    array<int,9> from,to;
    rep(i,0,8) {
        char ch; cin >> ch;
        from[i] = ch - '0';
    }
    rep(i,0,8) {
        char ch; cin >> ch;
        to[i] = ch - '0';
    }
    int pos[9];
    rep(i,0,8) {
        pos[from[i]] = i+1;
    }
    rep(i,0,8) {
        to[i] = pos[to[i]];
    }
    if(mp.count(to)) {
        cout << mp[to] << endl;
    } else {
        cout << -1 << endl;
    }
}
auto make_right(array<int,9> x, int i) {
    tie(x[i*3],x[i*3+1],x[i*3+2]) = make_tuple(x[i*3+2],x[i*3],x[i*3+1]);
    return x;
}
auto make_down(array<int,9> x, int i) {
    tie(x[i],x[i+3],x[i+6]) = make_tuple(x[i+6],x[i],x[i+3]);
    return x;
}
auto make_rotate(array<int,9> x) -> array<int,9> {
    return {x[6],x[3],x[0],x[7],x[4],x[1],x[8],x[5],x[2]};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<array<int,9>> que;
    array<int,9> beg{1,2,3,4,5,6,7,8,9};
    que.push(beg);
    mp[beg] = 0;
    while(!que.empty()) {
        auto now = que.front(); 
        que.pop();
        int step = mp[now];
        array<int,9> to;
        for(int i=0;i<3;i++) {
            to = make_right(now, i);
            if(!mp.count(to)) {
                mp[to] = step + 1;
                que.push(to);
            }
        }
        for(int i=0;i<3;i++) {
            to = make_down(now, i);
            if(!mp.count(to)) {
                mp[to] = step + 1;
                que.push(to);
            }
        }
        to = make_rotate(now);
        if(!mp.count(to)) {
            mp[to] = step + 1;
            que.push(to);
        }
    }
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

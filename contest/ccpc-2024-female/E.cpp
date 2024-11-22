#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define rep(i, o, p) for(int i = o ; i <= p; i ++)

constexpr int N = 2e5+10;

int fa[N];

int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}


vector<int> v[N];

void solve() {
    int n;
    cin >> n;
    rep(i, 1, n) {
        fa[i] = i;
        v[i].clear();
    }
    rep(i, 1, n) {
        int x; 
        cin >> x;
        rep(j, 1, x){
            int l;
            cin >> l;
            v[i].push_back(l);
        }
    }
    for(int i = n; i >= 1; i --){
        int l = v[i].size();
        rep(j, 0, l - 1){
            int y = v[i][j];
            cout << i << " " << find(y) << endl;
            fa[find(y)] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
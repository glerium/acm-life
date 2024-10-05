#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1e9+7;
int t, n, m;
vector<vector<char>> ch;

struct dsu {
    vector<int> fa;
    void init(int n) {
        fa.resize(n+5);
        for(int i=1;i<=n;i++)
            fa[i] = i;
    }
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y){
        // cout << "merging " << x << ' ' << y << endl;
        x = find(x); y = find(y);
        fa[x] = y;
    }
} d;

void solve() {
    cin >> n >> m;
    ch = vector<vector<char>>(n+5, vector<char>(m+5));
    d.init(n * 2);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            cin >> ch[i][j];
    }
    for(int l=1,r=m;l<=r;l++,r--) {
        int ct = 0;
        vector<array<int,2>> one;
        for(int j=1;j<=n;j++) {
            if(ch[j][l] == '1') {
                ct++;
                one.push_back({j, 0});
            }
            if(ch[j][r] == '1') {
                ct++;
                one.push_back({j, 1});
            }
        }
        if(ct > 2) {
            cout << 0 << endl;
            return;
        }else if(ct <= 1) {
            continue;
        }else{
            if(one[0][0] == one[1][0])
                continue;
            else {
                if(one[0][1] == one[1][1]) {
                    d.merge(one[0][0], one[1][0]+n);
                    d.merge(one[1][0], one[0][0]+n);
                }else{
                    d.merge(one[0][0], one[1][0]);
                    d.merge(one[0][0]+n, one[1][0]+n);
                }
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(d.find(i) == d.find(i+n)) {
            cout << 0 << endl;
            return;
        }
    }
    long long ans = 1;
    for(int i=1;i<=n;i++)
        d.merge(i, i+n);
    set<int> st;
    for(int i=1;i<=n;i++) {
        int tmp = d.find(i);
        if(!st.count(tmp)) {
            st.insert(tmp);
            ans = ans * 2 % mod;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
constexpr int maxn = 2e5+10;
int n,fa[maxn],ct,root,d[maxn];
set<int> a[maxn];
void add(int x,int y){
    a[x].insert(y);
    d[x]++; d[y]++;
}
void dfs(int x) {
    cout << x << ' ';
    for(auto i : a[x])
        dfs(i);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> fa[i];
        if(fa[i] == 0)
            root = i;
        else
            add(fa[i], i);
    }
    int k = -1;
    rep(i,1,n) {
        if(root == i) k = max(k, d[i]);
        else k = max(k, d[i] - 1);
    }
    bool ok = true;
    rep(i,1,n) {
        int du;
        if(root == i) du = d[i];
        else du = d[i] - 1;
        if(du == 0) continue;
        else if(du != k) {
            ok = false;
            break;
        }
    }
    cout << k << ' ' << (ok ? "yes" : "no") << endl;
    dfs(root);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e3+10;
constexpr int maxm = 2e5+10;
int n,m;
vector<int> v;
struct Edge {
    int x, y;
    int len;
    bool operator<(const Edge& rhs)const{
        return len < rhs.len;
    }
}a[maxm];
struct MFS {
    int fa[maxn];
    void init(int x) {
        for(int i=1;i<=x;i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        fa[x] = y;
    }
}mfs;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    mfs.init(n);
    for(int i=1;i<=m;i++) 
        cin >> a[i].x >> a[i].y >> a[i].len;
    sort(a+1, a+1+m);
    int ans = 0;
    int ct = 0;
    for(int i=1;i<=m;i++) {
        int x = a[i].x, y = a[i].y;
        if(mfs.find(x) == mfs.find(y))
            continue;
        ans += a[i].len;
        ct++;
        mfs.merge(x, y);
    }
    if(ct == n - 1)
        cout << ans << endl;
    else
        cout << "orz" << endl;
    return 0;
}
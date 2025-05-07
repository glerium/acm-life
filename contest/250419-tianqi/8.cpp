#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
struct Building {
    int x,y;
    int val;
    bool operator<(const Building& rhs) const {
        return val < rhs.val;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k; cin >> n >> m >> k;
    priority_queue<Building> q;
    auto a = Vec<int>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    rep(i,1,n) rep(j,1,m) {
        q.push({i, j, a[i][j]});
    }
    bool vx[n+5] = {}, vy[m+5] = {};
    while(k--) {
        while(vx[q.top().x] || vy[q.top().y]) {
            q.pop();
        }
        vx[q.top().x] = true;
        vy[q.top().y] = true;
        q.pop();
    }
    vector<vector<int>> vec;
    rep(i,1,n) {
        if(vx[i]) continue;
        vector<int> tmp;
        rep(j,1,m) {
            if(vy[j]) continue;
            tmp.push_back(a[i][j]);
        }
        vec.push_back(tmp);
    }
    for(auto &i : vec) {
        rep(j,0,i.size()-1) {
            cout << i[j] << " \n"[j == i.size() - 1];
        }
    }
}
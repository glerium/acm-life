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
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n; cin >> n;
    multiset<int, greater<int>> vec;
    vector<pair<int,int>> pt;
    rep(i,1,n) {
        int x1, y1, z1, x2, y2, z2;
        scanf("%d:%d:%d %d:%d:%d", &x1, &y1, &z1, &x2, &y2, &z2);
        int t1 = x1 * 3600 + y1 * 60 + z1;
        int t2 = x2 * 3600 + y2 * 60 + z2;
        pt.push_back({t1, t2});
    }
    sort(pt.begin(), pt.end());
    for(auto &i : pt) {
        auto fnd = vec.upper_bound(i.first);
        if(fnd == vec.end()) {
            vec.insert(i.second);
        }else{
            vec.erase(fnd);
            vec.insert(i.second);
        }
    }
    cout << vec.size() << endl;
    return 0;
}

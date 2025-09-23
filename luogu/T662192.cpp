#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n,m; cin >> n >> m;
    map<string,int> mp;
    vector<string> rmp(n+5);
    rep(i,1,n) {
        string s; cin >> s;
        mp[s] = i;
        rmp[i] = s;
    }
    set<int> st, cheat;
    st.insert(1);
    rep(i,1,m) {
        string xs,_,ys; cin >> xs >> _ >> ys;
        int x = mp[xs], y = mp[ys];
        if(!st.count(x)) {
            cheat.insert(x);
        } else {
            st.erase(x);
        }
        st.insert(y);
    }
    vector<string> vec;
    for(auto i : cheat)
        vec.push_back(rmp[i]);
    sort(vec.begin(), vec.end());
    cout << vec.size() << endl;
    for(auto i : vec) cout << i << ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
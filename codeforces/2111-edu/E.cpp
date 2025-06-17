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
    int n,q; cin >> n >> q;
    string s; cin >> s; s = ' ' + s;
    map<pair<char,char>, set<int>> mp;
    rep(i,1,q) {
        char x,y; cin >> x >> y;
        mp[{x,y}].insert(i);
    }
    rep(i,1,n) {
        if(s[i] == 'a') continue;
        else if(s[i] == 'b') {
            auto &tmp = mp[{'b','a'}];
            if(!tmp.empty()) {
                s[i] = 'a';
                tmp.erase(tmp.begin());
            }else{
                auto &tmp1 = mp[{'b','c'}];
                auto &tmp2 = mp[{'c','a'}];
                if(!tmp1.empty()) {
                    auto pos1 = *tmp1.begin();
                    set<int>::iterator fnd;
                    if((fnd = tmp2.lower_bound(pos1)) != tmp2.end()) {
                        // ok
                        s[i] = 'a';
                        tmp1.erase(tmp1.begin());
                        tmp2.erase(fnd);
                    }
                }
            }
        }else {     // s[i] == 'c'
            auto &tmp = mp[{'c','a'}];
            if(!tmp.empty()) {
                s[i] = 'a';
                tmp.erase(tmp.begin());
            } else {
                auto &tmp1 = mp[{'c','b'}];
                if(!tmp1.empty()) {
                    auto pos1 = *tmp1.begin();
                    auto &tmp2 = mp[{'b','a'}];
                    set<int>::iterator fnd;
                    if((fnd = tmp2.lower_bound(pos1)) != tmp2.end()) {
                        s[i] = 'a';
                        tmp1.erase(tmp1.begin());
                        tmp2.erase(fnd);
                    } else {
                        s[i] = 'b';
                        tmp1.erase(tmp1.begin());
                    }
                }
            }
        }
    }
    cout << s.substr(1) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

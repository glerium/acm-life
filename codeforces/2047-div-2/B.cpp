#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; string s; 
    cin >> n >> s;
    int mx = 0;
    string mis = s;
    auto getp1 = [&](string s) -> int{
        map<char,int> mp;
        for(auto i : s)
            mp[i]++;
        int ret = 1;
        for(auto [x,y] : mp) {
            rep(i,1,y)
                ret *= i;
        }
        return ret;
    };
    mx = getp1(s);
    rep(i,0,n-1) {
        rep(j,0,n-1) {
            char old = s[j];
            s[j] = s[i];
            if(mx < getp1(s)) {
                mis = s;
                mx = getp1(s);
            }
            s[j] = old;
        }
    }
    cout << mis << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

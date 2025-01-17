#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    int fz = 0;
    for(int i=1;i<=n;i++) {
        if(s[i] == '0') {
            fz = i;
            break;
        }
    }
    if(!fz) {
        cout << 1 << ' ' << n << ' ' << n << ' ' << n << endl;
        return;
    }
    int rfz = n - fz + 1;
    vector<pair<string,int>> vec;
    for(int i=1;i+rfz-1<=n;i++) {
        string now = " ";
        for(int l=i,r=fz;l<=n&&r<=n;l++,r++) {
            now += ((s[l] - '0') ^ (s[r] - '0')) + '0';
        }
        vec.push_back({now, i});
    }
    // for(auto [x, y] : vec) {
    //     cout << x << ' ' << y << endl;
    // }
    sort(vec.begin(), vec.end());
    int best = (*--vec.end()).second;
    cout << 1 << ' ' << n << ' ' << best << ' ' << best + rfz - 1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

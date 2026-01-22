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
    int n; cin >> n;
    string s; cin >> s;
    string a, b;
    int ct1 = 0;
    rep(i,0,n-1) ct1 += s[i] == '1';
    b += string(ct1, '1');
    // b += string(n - ct1, '0');
    a += string(n, '0');
    vector<int> pos1;
    reverse(s.begin(), s.end());
    rep(i,0,n-1) {
        if(s[i] == '1') {
            pos1.push_back(i);
        }
    }
    // reverse(pos1.begin(), pos1.end());
    int idx = 0;
    while(true) {
        if(pos1.empty()) break;
        int loss = b.size() - 1;
        int gain = pos1[idx];
        if(gain >= loss) break;
        idx++;
        b.pop_back();
        a[gain] = '1';
    }
    b += string(n - b.size(), '0');
    vector<int> aa, bb;
    for(auto ch : a) aa.push_back(ch - '0');
    for(auto ch : b) bb.push_back(ch - '0');
    int x = aa.size(), y = bb.size();
    for(int i=0; i<x&&i<y; i++) {
        aa[i] += bb[i];
        if(aa[i] > 1) {
            aa[i + 1] += aa[i] / 2;
            aa[i] %= 2;
        }
    }
    reverse(aa.begin(), aa.end());
    bool flag = true;
    for(auto i : aa) {
        if(flag && i == 0) continue;
        flag = false;
        cout << i;
    }
    if(flag) cout << 0;
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
constexpr int cp[4][2] = {{8,8},{6,9},{0,0},{9,6}};
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    // int n = rand() % 5 + 1;
    // string s = " ";
    // string rr = "0689";
    // rep(i,1,n) {
    //     s += rr[rand() % 4];
    // }
    auto p = Vec<int>(n+5, 10, 0);
    rep(i,1,n) {
        rep(j,0,9)
            p[i][j] = p[i-1][j] + (s[i] == j + '0');
    }
    ll ans = 0;
    bool ori = false;
    rep(i,1,n) {
        if(s[i] == '0' || s[i] == '8')
            ori = true;
    }
    rep(i,2,n) {
        if(s[i-1] == '9' && s[i] == '6' || s[i-1] == '6' && s[i] == '9')
            ori = true;
    }
    rep(i,1,n) {
        if(s[i] == '0') {
            ans += n - i + 1 - (p[n][0] - p[i - 1][0]);
        } else if(s[i] == '8') {
            ans += n - i + 1 - (p[n][8] - p[i - 1][8]);
        } else if(s[i] == '6') {
            ans += n - i + 1 - (p[n][9] - p[i - 1][9]);
        } else {
            ans += n - i + 1 - (p[n][6] - p[i - 1][6]);
        }
    }
    ans += ori;
    // ll ans2 = 0;
    // set<string> st;
    // // st.insert(s);
    // rep(l,1,n) rep(r,l,n) {
    //     string sub = s.substr(l, r - l + 1);
    //     reverse(sub.begin(), sub.end());
    //     for(auto &ch : sub) {
    //         rep(j,0,3) {
    //             if(ch == '0' + cp[j][0]) {
    //                 ch = '0' + cp[j][1];
    //                 break;
    //             }
    //         }
    //     }
    //     string t = s.substr(0, l) + sub + s.substr(r + 1);
    //     // cout << l << ' ' << r << ' ' << t << endl;
    //     st.insert(t);
    // }
    // ans2 = st.size();
    // if(ans != ans2) {
    //     cout << n << endl;
    //     cout << s << endl;
    //     cout << ans << ' ' << ans2 << endl;
    //     exit(0);
    // }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // srand(time(0));
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
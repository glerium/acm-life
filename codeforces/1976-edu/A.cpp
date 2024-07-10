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
    bool ok = true;
    for(int i=0;i<n-1;i++) {
        if(isalpha(s[i]) && isdigit(s[i+1])) {
            ok = false;
        }
    }
    char mx = 0;
    for(int i=0;i<n;i++) {
        if(!isalpha(s[i])) continue;
        if(s[i] < mx) {
            ok = false;
        }
        mx = s[i];
    }
    mx = 0;
    for(int i=0;i<n;i++) {
        if(!isdigit(s[i])) continue;
        if(s[i] < mx) {
            ok = false;
        }
        mx = s[i];
    }
    puts(ok ? "YES" : "NO");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

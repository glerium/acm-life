#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    string s; cin >> s;
    for(int i=s.size() - 2; i >= 0; i--) {
        if(s[i] == 'W' && s[i+1] == 'A') {
            s[i] = 'A';
            s[i+1] = 'C';
        }
    }
    cout << s << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}

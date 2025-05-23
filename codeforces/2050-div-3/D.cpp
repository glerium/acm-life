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
    int a[n+5] = {};
    rep(i,1,n) a[i] = s[i-1] - '0';
    rep(i,1,n) {
        int j = i;
        while(j >= 2 && j >= i - 10) {
            if(a[j] - 1 > a[j-1]) {
                a[j]--;
                swap(a[j], a[j-1]);
                j--;
            }else break;
        }
    }
    rep(i,1,n) cout << a[i];
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

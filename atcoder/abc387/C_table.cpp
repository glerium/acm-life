#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
bool check(int x) {
    if(x < 10) return false;
    int a[10] = {};
    int ct = 0;
    while(x) {
        a[++ct] = x % 10;
        x /= 10;
    }
    rep(i,1,ct-1) {
        if(a[ct] <= a[i])
            return false;
    }
    return true;
}
int ct(int x) {
    int ret = 0;
    rep(i,1,x) ret += check(i);
    return ret;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    while(true) {
        int n; cin >> n;
        cout << ct(n) << endl;
    }
    return 0;
}

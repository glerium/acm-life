#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int gsum(int x) {
    int ret = 0;
    while(x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n; cin >> n;
    if(n.size() <= 6) {
        int n_ = atoi(n.c_str());
        rep(i,n_,2*n_-1) {
            int a = i, b = i+1;
            if(a % gsum(a) == 0 && b % gsum(b) == 0) {
                cout << a << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    }else{
        int r = (n[0] - '0') * 10 + (n[1] - '0');
        string ans;
        if(r <= 16) ans = "17";
        else if(r <= 25) ans = "26";
        else if(r <= 43) ans = "44";
        else if(r <= 61) ans = "62";
        else if(r <= 70) ans = "71";
        else ans = "107";
        ans += string(n.size() - 2, '0');
        cout << ans << endl;
    }
    return 0;
}

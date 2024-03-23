#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 3e5+10;
constexpr ll mod = 998244353;
int n, ctl[maxn][2], ctr[maxn][2];
string s;
bool cmp(int x, int y) {
    if(abs(n - 2 * x) != abs(n - 2 * y)) {
        return abs(n - 2 * x) < abs(n - 2 * y);
    }else{
        return x < y;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        cin >> n >> s;
        s = ' ' + s;
        vector<int> ok;
        ctl[0][0] = ctl[0][1] = ctr[n+1][0] = ctr[n+1][1] = 0;
        for(int i=1;i<=n;i++) {
            ctl[i][0] = ctl[i-1][0] + (s[i] == '0');
            ctl[i][1] = ctl[i-1][1] + (s[i] == '1');
        }
        for(int i=n;i>=0;i--) {
            ctr[i][0] = ctr[i+1][0] + (s[i] == '0');
            ctr[i][1] = ctr[i+1][1] + (s[i] == '1');
        }
        for(int i=0;i<=n;i++) {
            if(ctl[i][0] * 2 >= i && ctr[i+1][1] * 2 >= n - i) {
                ok.push_back(i);
            }
        }
        sort(ok.begin(), ok.end(), cmp);
        cout << ok[0] << endl;
    }
    return 0;
}

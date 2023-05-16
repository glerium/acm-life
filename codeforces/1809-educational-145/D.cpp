#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
const long long swp = 1e12, del = 1e12+1;
int t;
typedef long long ll;
string s;
//后i个字符满足不下降的钱数，状态：0:仅有1，1:有一个0，2:有多于一个0，3：全为0
__int128 f[maxn][5];
int main() {
    cin>>t;
    while(t--) {
        cin>>s;
        int n = s.size();
        if(s[n-1] == '0') {
            f[1][0] = del;
            f[1][1] = 0;
            f[1][2] = 0;
            f[1][3] = 0;
        } else {
            f[1][0] = 0;
            f[1][1] = 1e24;
            f[1][2] = 1e24;
            f[1][3] = del;
        }
        for(int i=2; i<=n; i++) {
            if(s[n-i] == '0') {
                f[i][0] = f[i-1][0] + del;
                f[i][1] = f[i-1][0];
                f[i][2] = min(f[i-1][1], f[i-1][2]);
                f[i][3] = f[i-1][3];
            } else {    // s[i] == '1'
                f[i][0] = f[i-1][0];
                f[i][1] = f[i-1][1] + swp;
                f[i][2] = f[i-1][2] + del;
                f[i][3] = f[i-1][3] + del;
            }
        }
        long long ans = min(f[n][0], min(f[n][1], min(f[n][2], f[n][3])));
        cout << (long long)ans << endl;
        // cout << "table: " << endl;
        // for(int i=1; i<=n; i++) cout << (ll)f[i][0] << ' ' << (ll)f[i][1] << ' ' << (ll)f[i][2] <<' '<<(ll)f[i][3]<< endl;
    }
    return 0;
}
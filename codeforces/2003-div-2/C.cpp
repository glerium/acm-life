#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; string s; cin >> n >> s;
    int ct[26] = {};
    for(auto ch : s) ct[ch - 'a']++;
    string ans;
    char last = 0;
    {
        int mx = 0;
        for(int i=0;i<26;i++) {
            if(ct[i] > mx) {
                mx = ct[i];
                last = i + 'a';
            }
        }
        ans += last;
        ct[last - 'a']--;
    }
    for(int i=2;i<=n;i++) {
        if(ct[last - 'a'] == n-i+1) {
            ans += last;
            ct[last - 'a']--;
        }else{
            int mx = 0;
            for(int j=0;j<26;j++) {
                if(j == last - 'a')
                    continue;
                if(ct[j] > mx) {
                    mx = ct[j];
                    last = j + 'a';
                }
            }
            ans += last;
            ct[last - 'a']--;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

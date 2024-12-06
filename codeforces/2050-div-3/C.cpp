#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    string s; cin >> s;
    int sum = 0;
    int two = 0, three = 0;
    for(auto i : s) {
        sum += i - '0';
        if(i == '2')
            two++;
        else if(i == '3')
            three++;
    }
    if(sum % 9 == 0) {
        cout << "YES" << endl;
        return;
    } else {
        // two: 2; three: 6;
        for(int i=0;i<=min(10, two);i++) {
            for(int j=0;j<=min(10, three);j++) {
                if((sum + i * 2 + j * 6) % 9 == 0) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

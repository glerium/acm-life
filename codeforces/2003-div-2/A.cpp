#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
#define yes puts("yes")
#define no puts("no")
    if(s[0] == s[s.size()-1]) {
        no;
    }else{
        bool found = false;
        for(int i=0;i<s.size()-1;i++) {
            if(s[i] != s[i+1])
                found = true;
        }
        if(found) yes;
        else no;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

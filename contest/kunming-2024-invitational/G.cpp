#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
using ll = long long;
void solve() {
    int n; cin >> n;
    int now = 0;
    vector<int> ans;
    int tmp = -1;
    rep(i,0,n-1) {
        if(tmp != -1) {
            now ^= i;
            ans.push_back(i);
            ans.push_back(tmp);
            tmp = -1;
        }else {
            now ^= i;
            if(now == 0) {
                tmp = i;
            } else {
                ans.push_back(i);
            }
        }
    }
    if(now == 0) 
        cout << "impossible" << endl;
    else {
        for(auto i : ans)
            cout << i << ' ';
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
}
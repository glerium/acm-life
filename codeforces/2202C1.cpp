#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    stack<int> stk;
    for(int i=n;i>=1;i--) {
        while(!stk.empty() && stk.top() == a[i]+1) {
            stk.pop();
        }
        stk.push(a[i]);
    }
    cout << stk.size() << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn = 2e3+10;
int n,ct[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n*(n-1)/2;i++) {
        int x,y; cin>>x>>y;
        y = max(x,y);
        if(++ct[y]==y) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
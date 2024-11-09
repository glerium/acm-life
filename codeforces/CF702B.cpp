#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n+5];
    for(int i=1;i<=n;i++) cin >> a[i];
    map<int,int> st;
    for(int i=1;i<=n;i++) st[a[i]]++;
    long long ct = 0;
    for(auto [i,c] : st) {
        for(int j=0;j<31;j++) {
            if((1<<j)-i > i) continue;
            if(st.count((1<<j)-i)) {
                if(i != (1<<j)-i)
                    ct += 1ll * st[(1<<j)-i] * st[i];
                else
                    ct += 1ll * st[i] * (st[i]-1) / 2;
            }
        }
    }
    cout << ct << endl;
    return 0;
}
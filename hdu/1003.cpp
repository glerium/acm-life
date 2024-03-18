#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
int t, n, a[maxn], f[maxn], l[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    for(int _=1; _<=t; _++) {
        f[0] = -1e5;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        for(int i=1;i<=n;i++) {
            if(f[i-1] + a[i] < a[i]) {
                f[i] = a[i];
                l[i] = i;
            }else{
                f[i] = f[i-1] + a[i];
                l[i] = l[i-1];
            }
        }
        int mx = -1e5, mxl, mxr;
        for(int i=1;i<=n;i++) {
            if(mx < f[i]) {
                mx = f[i];
                mxl = l[i];
                mxr = i;
            }
        }
        cout << "Case" << ' ' << _ << ":" << endl;
        cout << mx << ' ' << mxl << ' ' << mxr << endl;
        if(_ !=t) cout << endl;
    }
    return 0;
}
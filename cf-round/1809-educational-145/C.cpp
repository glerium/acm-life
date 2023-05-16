
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
int t, n, k;
int ct[40];
int main() {
    for(int i=1;i<=30;i++) ct[i] = i*(i+1)/2;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int minus_ct;
        for(int i=30;i>=1;i--) if(ct[i] <= k) minus_ct = i;
        int ans[40];
        for(int i=n;i>=n-minus_ct+1;i--) ans[i] = -(1000/minus_ct)+(n-i+1);
        int cc = minus_ct, rem = k - ct[minus_ct];
        for(int i=n-minus_ct;i>=1;i--)  {
            if(rem <= cc) ans[i] = -1, rem -= cc;
            else ans[i] =  
        }
    }
    return 0;
}
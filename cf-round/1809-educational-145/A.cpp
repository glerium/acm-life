#include <bits/stdc++.h>
using namespace std;
int t, n, ct[10];
string s;
int main() {
    cin>>t;
    while(t--) {
        cin>>s;
        memset(ct, 0, sizeof(ct));
        for(auto ch : s) ct[ch-'0']++;
        int sum = 0, mx = 0;
        for(int i=0; i<=9; i++) {
            sum += ct[i];
            mx = max(mx, ct[i]);
        }
        int ans = -1;
        if(sum == mx || (mx > sum-mx && (sum-mx%2==1)))
            ans = -1;
        else if(mx > sum - mx) ans = sum + 2 * (sum - mx);
        else ans = sum;
        cout << ans << endl;
    }
    return 0;
}
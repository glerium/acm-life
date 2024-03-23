#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t; cin >> t;
    while(t--) {
        ll a,b,c; cin>>a>>b>>c;
        ll ans = 0;
        ans += a;
        ans += b / 3;
        b %= 3;
        if(b + c < 3 && b % 3 != 0){
            cout << -1 << endl;
            continue;
        }else{
            ans += (b + c) / 3 + bool((b + c) % 3);
            cout << ans << endl;
        }
    }
}
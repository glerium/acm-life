#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        long long T; cin >> T;
        long long w = min(T, 1 + (1+T)/2);
        long long fenzi=2*T-2*w+w*(w+1);
        long long fenmu=2*w;
        long long _gcd=gcd(fenzi,fenmu);
        fenzi/=_gcd;
        fenmu/=_gcd;
        cout<<fenzi<<' '<<fenmu<<'\n';
    }
}
#include <iostream>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;
vector<array<ll,2>> split(ll x) {
    vector<array<ll,2>> ans;
    for(int i=2;i*i<=x;i++) {
        int ct = 0;
        while(x%i==0) {
            x /= i;
            ct++;
        }
        if(ct) ans.push_back({i, ct});
    }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
int main() {
    int t; cin >> t;
    while(t--) {
        ll x; int lim; cin >> x >> lim;
        auto ret = split(x);
        for(auto _ : ret) {
            int i = _[0], ct = _[1];
            if(ct < lim) {
                for(int j = 1; j <= ct; j++)
                    x /= i;
            }
        }
        cout << x << endl;
    }
    return 0;
}
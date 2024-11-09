#include <bits/stdc++.h>
#define yes s += '1'
#define no s += '0'
using namespace std;
constexpr int maxn = 1e5+10;
int n, a[maxn];
int main() {
    ios::sync_with_stdio(false);
    int x,y,z,t1,t2,t3; cin >> x >> y >> z >> t1 >> t2 >> t3;
    if(t1*abs(x-y) >= t3*3+t2*(abs(z-x)+abs(y-x))) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
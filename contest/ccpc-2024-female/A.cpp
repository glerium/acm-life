#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int z,h,u0,v0,u1,v1;
    cin >> z >> h >> u0 >> v0 >> u1 >> v1;
    if(u0 > u1) swap(u0, u1);
    if(v0 > v1) swap(v0, v1);
    int z0=z, z1=z+h;
    int q; cin >> q;
    while(q--) {
        int uu,vv,zz; cin >> uu >> vv >> zz;
        if(u0 <= uu && uu <= u1 && v0 <= vv && vv <= v1 && z0 <= zz && zz <= z1) {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

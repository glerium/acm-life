#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef __int128_t ll;
ll mygcd(ll x, ll y) {
    return !y ? x : mygcd(y, x%y);
}
struct Frac {
    ll x,y;
    Frac() = default;
    Frac(ll x, ll y) : x(x), y(y) {hj();}
    void hj() {
        ll gg = mygcd(x, y);
        x /= gg; y /= gg;
    }
    Frac operator+(const Frac& rhs)const{
        ll tx = x*rhs.y + y*rhs.x;
        ll ty = rhs.y * y;
        Frac frac = {tx, ty};
        frac.hj();
        return frac;
    }
    bool operator<(const Frac& rhs)const {
        return x*rhs.y < y*rhs.x;
    }
    bool operator>(const Frac& rhs)const {
        return x*rhs.y > y*rhs.x;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    while(n--) {
        long long t; cin >> t;
        Frac ans = {t, 1};
        long long mid = sqrtl(2 * t);
        long long l = max(1ll, mid - 1),
                  r = min(t, mid + 1);
        for(ll i = l; i <= r; i++) {
            Frac now = Frac(i-1, 2) + Frac(t, i);
            // cout << now.x << ' ' << now.y << endl;
            if(now < ans)
                ans = now;
        }
        cout << (long long)(ans.x) << ' ' << (long long)(ans.y) << endl;
    }
}
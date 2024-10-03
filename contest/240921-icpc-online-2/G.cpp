#include <bits/stdc++.h>

#define rep(i, o, p) for(int i = o; i <= p; i ++ )
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr int p = 998244353;
ll qpow(ll a,ll b)
{
    a%=p;
    ll res=1;
    while(b)
    {
        if(b&1) res = res * a % p;
        a = a * a % p;
        b>>=1;
    }
    return res%p;
}
ll inv(ll n){return qpow(n,p-2);}


void solve(){
//	rep(i, 1, 10) cout << inv(inv(i)) << " ";
//	cout << inv(499122177) << " ";
	ll x, y;
	cin >> x >> y;
	ll a, b, c;
	cin >> a >> b >> c;
	ll p0, p1;
	p0 = a * inv(c) % p;
	p1 = b * inv(c) % p;
	ll p2 = p0 * inv(p0 + p1) % p;
	ll p3 = p1 * inv(p0 + p1) % p;
	p0 = p2; 
	p1 = p3;
//	cout << p0 << " " << p1 << '\n';
	ll ans = 0, pc = 1;
	while(x != 0 && y != 0){
	//	cout << pc << " ]";
		if(x < y){
			pc = pc * qpow(p0, y / x) % p;
			y = y % x;
			if(y == 0) ans = (ans + pc) % p;
		}
		else{
		//	cout << qpow(p0, x / y) << " ";
			ans += pc * ((1 - qpow(p1, x / y) + p) % p) % p;
			ans %= p;
		//	cout << pc * ((1 - inv(pow(pc, x / y - 1) ) + p) % p) % p << " ";
			pc = pc * qpow(p1, x / y) % p;
			x = x % y;
		}
	}
	cout << ans % p << '\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;while(t--)solve();
    return 0;
}

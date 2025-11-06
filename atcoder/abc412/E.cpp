#include <bits/stdc++.h>
#define rep(i,x,y) for(ll i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int main() {
	ll l,r; cin >> l >> r;
	
	l++;
	ll ans = 1;
	ll lim = sqrt(r) + 1;
	
	vector<bool> pri(lim+5);
	rep(i,1,lim) pri[i] = true;
	pri[1] = false;
	pri[2] = true;
	rep(i,2,lim) {
		if(!pri[i]) continue;
		for(ll j=i+i;j<=lim;j+=i) {
			pri[j] = false;
		}
	}
	
	rep(i,2,lim) {
		if(!pri[i]) continue;
		ll now = i;
		while(now <= r) {
			if(now >= l) ans++;
			now *= i;
		}
	}
	
	vector<ll> primes;
	rep(i,1,lim) {
		if(pri[i])
			primes.push_back(i);
	}
	
	vector<bool> isprime(r - l + 10);
	rep(i,l,r) isprime[i-l] = true;
	for(auto i : primes) {
		ll begin = (l / i + bool(l % i)) * i;
		for(ll j=begin;j<=r;j+=i) {
			isprime[j-l] = false;
		}
	}
	rep(i,l,r) {
		if(isprime[i-l])
			ans++;
	}
	cout << ans << endl;
	return 0;
}

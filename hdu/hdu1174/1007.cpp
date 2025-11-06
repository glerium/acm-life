#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
void solve() {
	mt19937_64 rng(random_device{}());
	int n; cin >> n;
	vector<int> l(n+5), r(n+5);
	rep(i,1,n) cin >> l[i] >> r[i];
	vector<int> all;
	rep(i,1,n) {
		all.push_back(l[i]);
		all.push_back(r[i]+1);
	}
	sort(all.begin(), all.end());
	int last = -114514;
	map<int,int> mp;
	int ct = 0;
	vector<ll> w(n+5);
	rep(i,1,n) w[i] = rng();
	for(auto i : all) {
		if(i == last)
			continue;
		if(i - last >= 2) {
			mp[(i+last)/2] = ++ct;
		}
		mp[i] = ++ct;
		last = i;
	}
	auto add = [&](ll prev, ll x) -> ll {
		prev ^= w[x];
		return prev;
	};
	auto del = [&](ll prev, ll x) -> ll {
		prev ^= w[x];
		return prev;
	};
	rep(i,1,n) {
		l[i] = mp[l[i]];
		r[i] = mp[r[i]];
	}
	/*
	rep(i,1,n) {
		cerr <<":" << l[i] << ' ' << r[i] << endl;
	}
	*/
	vector<vector<int>> bg(ct+10), ed(ct+10);
	rep(i,1,n) {
		bg[l[i]].push_back(i);
		ed[r[i]].push_back(i);
	}
	set<ll> ans;
	ll status = 0;
	ans.insert(status);
	rep(i,1,ct) {
		for(auto j : bg[i]) {
			status = add(status, j);
		}
		for(auto j : ed[i-1]) {
			status = del(status, j);
		}
		ans.insert(status);
	}
	cout << ans.size() << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}

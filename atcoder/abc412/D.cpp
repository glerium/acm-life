#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int main() {
	int n,m; cin >> n >> m;
	set<pair<int,int>> st;
	rep(i,1,m) {
		int x,y; cin >> x >> y;
		st.insert({x,y});
		st.insert({y,x});
	}
	int ans = 0x3f3f3f3f;
	int a[n+2] = {};
	rep(i,1,n) {
		a[i] = i;
	}
	do {
		int hit = 0;
		a[n+1] = a[1];
		rep(i,1,n) {
			if(st.count({a[i],a[i+1]}))
				hit++;
		}
		int curAns = m - hit + (n - hit);
		ans = min(ans, curAns);
		//rep(i,1,n) {cout << a[i] << ' ';}
		//cout << endl << curAns << endl << endl;
	} while(next_permutation(a+1, a+1+n));
	
	
	do {
		for(int i=1;i<=n;i++) {
			if(i < 3 || n - i < 3) continue;
			// a[1] ... a[i], a[i+1] ... a[n]
			int hit = 0;
			rep(j,1,i-1) {
				if(st.count({a[j],a[j+1]}))
					hit++;
			}
			if(st.count({a[1], a[i]})) hit++;
			
			rep(j,i+1,n-1) {
				if(st.count({a[j],a[j+1]}))
					hit++;
			}
			if(st.count({a[i+1], a[n]})) hit++;
			int curAns = m - hit + (n - hit);
			ans = min(ans, curAns);
		}
		
		//rep(i,1,n) {cout << a[i] << ' ';}
		//cout << endl << curAns << endl << endl;
	} while(next_permutation(a+1, a+1+n));
	cout << ans << endl;
	return 0;
}

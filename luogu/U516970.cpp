#include <bits/stdc++.h>
using namespace std;
int main() {
	int q; cin >> q;
	long long m = 1e18;
	while(q--) {
		long long x; cin >> x;
		if(x == 0) cout << "1 1\n";
		else if(x == 1) cout << "-1 -1\n";
		else if(x <= m) cout << 1 << " "  << x << endl;
		else if(m % (x - m) != 0) cout << (long long)m << ' ' << (long long)(x - m) << endl;
		else {
			bool ok = false;
			for(int i=1;i<=100;i++) {
				long long a = m - i, b = x - a;
				if(a > m || b > m) continue;
				if(a%b && b%a) {
					cout << a << ' ' << b << endl;
					ok = true;
					break;
				}

			}
			if(!ok)
				cout << "-1 -1" << endl;
		}
	
	}
	return 0;
}

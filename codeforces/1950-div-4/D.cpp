#include <bits/stdc++.h>
using namespace std;
int t,n;
vector<int> a;
int main() {
    for(int i=2;i<(1<<5);i++) {
        int aa = 0;
        int base = 1;
        for(int j=0;j<=4;j++) {
            aa += bool(i & (1 << j)) * base;
            base *= 10;
        }
        a.push_back(aa);
    }
    a.push_back(100000);
    cin >> t;
    while(t--) {
        cin >> n;
        for(auto i = a.rbegin(); i != a.rend(); i++) {
            while(n % *i == 0) {
                n /= *i;
            }
        }
        puts(n == 1 ? "YES" : "NO");
    }
    return 0;
}
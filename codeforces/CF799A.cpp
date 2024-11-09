#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,t,k,d; cin>>n>>t>>k>>d;
    if((n/k+bool(n%k))*t <= d+t) {
        cout << "NO" << endl;
    } else cout << "YES" << endl;
}
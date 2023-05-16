#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (long long)(sqrt(n-1)) << endl;
    }
    return 0;
}
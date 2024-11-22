#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c; cin >> a >> b >> c;
    cout << 100 << endl;
    for(int i=1;i<=50;i++) cout << a << ' ';
    for(int i=1;i<=45;i++) cout << b << ' ';
    for(int i=1;i<=4;i++) cout << c << ' ';
    cout << c + 1 << endl;
    return 0;
}

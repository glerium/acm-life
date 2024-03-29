#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e3+10;
int n, a[maxn], b[maxn];
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        if(i==1) b[i]=(a[i]+a[i+1]) / 2;
        else if(i==n) b[i]=(a[i]+a[i-1])/2;
        else b[i] = (a[i]+a[i-1]+a[i+1])/3;
    }
    for(int i=1;i<=n;i++) cout << b[i] << ' ';
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=30;
int t,n,a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        puts(n%2==0?"zn":"qcjj");
    }
}
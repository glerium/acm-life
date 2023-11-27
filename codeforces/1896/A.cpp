#include <bits/stdc++.h>
using namespace std;
int t,n,a[15];
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int mi=1000;
        for(int i=1;i<=n;i++) mi=min(mi,a[i]);
        puts(mi==a[1]?"YES":"NO");
    }
    return 0;
}
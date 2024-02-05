#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,a[maxn];
int main() {
    ios::sync_with_stdio(false);
    a[1]=1,a[2]=3;
    for(int i=3;i<=2e5;i++) {
        int ima=a[i-1]+1;
        while(3*ima%(a[i-1]+a[i-2])==0) ima++;
        a[i]=ima;
    }
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<endl;
    }
}
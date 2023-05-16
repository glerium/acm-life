#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int mod=1e9+7;
int t,n,a[maxn],b[maxn],ct[maxn];
int main() {
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        sort(a+1,a+1+n,greater<int>());
        sort(b+1,b+1+n,greater<int>());
        int i=1,j=1;
        for(i=1,j=1;i<=n&&j<=n;j++) {
            while(a[i]>b[j]&&i<=n) i++;
            ct[j]=i-1;
        }
        for(;j<=n;j++) ct[j]=i-1;
        // for(int i=1;i<=n;i++) cout<<ct[i]<<' ';
        // cout<<endl;
        long long ans=1;
        for(int i=1;i<=n;i++) ans = (ans*(ct[i]+1-i))%mod;
        cout<<ans<<endl;
    }
    return 0;
}
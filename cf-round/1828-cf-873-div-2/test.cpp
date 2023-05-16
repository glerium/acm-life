#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int mod=1e9+7;
int t,n,a[maxn],b[maxn],ct[maxn];
set<int> st;
int main() {
    t=10000;
    while(t--){
        n=rand()%100+1;
        for(int i=1;i<=n;i++) {
            a[i]=rand();
            while(st.count(a[i])) a[i]=rand();
            st.insert(a[i]);
        }
        for(int i=1;i<=n;i++) b[i]=rand();
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
        int ans2=1;
        for(int i=1;i<=n;i++) {
            ans = (ans*(ct[i]+1-i))%mod;
            ans2 = (ans2*(ct[i]+1-i))%mod;
        }
        if(ans!=ans2) {
            cout<<"YES!!!"<<endl;
            cout<<ans<<endl<<ans2<<endl;
            freopen("test.in","w",stdout);
            cout<<n<<endl;
            for(int i=1;i<=n;i++) cout<<a[i]<<' ';
            cout<<endl;
            for(int i=1;i<=n;i++) cout<<b[i]<<' ';
            cout<<endl;
            return 0;
        }
    }
    return 0;
}
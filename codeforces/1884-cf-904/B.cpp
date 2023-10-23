#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int t,n,a[maxn],idx;
char s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>(s+1);
        idx=0;
        for(int l=1,r=n;l<r;l++,r--) swap(s[l],s[r]);
        int ct=0;
        for(int i=1;i<=n;i++) ct+=s[i]=='0';
        for(int i=1;i<=n;i++) {
            if(s[i]=='0')
                a[++idx]=i;
        }
        long long ans=0;
        for(int i=1;i<=n;i++) {
            if(i<=ct) {
                ans+=a[i]-i;
                cout<<ans<<' ';
            }else cout<<"-1 ";
        }
        cout<<endl;
    }
}
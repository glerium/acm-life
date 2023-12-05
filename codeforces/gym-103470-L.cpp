#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int n,f[maxn];
char s[maxn];
vector<int> v[3][2];
int main() {
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--) {
        cin>>n>>(s+1);
        s[n+1]=s[1],s[n+2]=s[2],s[n+3]=s[3];
        for(int i=1;i<n;i++) {
            int bef=i==1?n:i-1,
                aft=i==n?1:i+1;
            if(s[i]!=s[i+1]) {
                f[aft]=!f[bef];
            }else{
                f[aft]=f[bef];
            }
        }
        for(int i=1;i<=n;i++) cout<<f[i]<<' ';
        cout<<endl;
    }
}
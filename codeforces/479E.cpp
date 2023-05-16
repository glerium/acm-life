#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
const ll mod=1e9+7;
int n,a,b,kk;
ll f[maxn];   // 在第i回合位于j点的总方案数
ll s[maxn];   // f在行意义上的一维前缀和
int main() {
    cin>>n>>a>>b>>kk;
    f[a]=1;
    for(int j=1;j<=n;j++) s[j]=s[j-1]+f[j];
    for(int i=1;i<=kk;i++) {
        for(int j=1;j<=n;j++) {
            if(j==b) continue;
            else if(j<b) f[j]=((s[j-1]+(s[j+(b-j-1)/2]-s[j]))%mod+mod)%mod;
            else f[j]=(((s[n]-s[j])+(s[j-1]-s[j-(j-b-1)/2-1]))%mod+mod)%mod;
        }
        for(int j=1;j<=n;j++) s[j]=((s[j-1]+f[j])%mod+mod)%mod;
    }
    cout<<s[n]<<endl;
    return 0;
}
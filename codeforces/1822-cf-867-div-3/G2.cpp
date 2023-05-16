#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int mx=1e9+10;
int n,a[maxn],pri[maxn],dpri[maxn],ctp;
bitset<maxn> ispri;
map<int,int> ct;
void init(){
    ispri.set();
    ispri[1]=false;
    for(int i=2;i*i<=mx;i++) {
        if(ispri[i]) {
            for(ll j=i<<1;j*j<=mx;j+=i)
                ispri[j]=false;
        }
    }
    for(int i=2;i*i<=mx;i++) {
        if(ispri[i]){
            pri[++ctp] = i;
            dpri[ctp] = i*i;
        }
    }
}
int main(){
    init();
    int _; cin>>_;
    while(_--){
        ct.clear();
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            ct[a[i]]++;
        }
        ll ans=0;
        for(int i=1;i<=n;i++) {
            ans += 1ll*(ct[a[i]]-1)*(ct[a[i]]-2);
            for(int j=1;j<=ctp;j++) {
                if(a[i]%dpri[j]==0 && dpri[j]<=a[i]) {
                    ans += 1ll*ct[a[i]/pri[j]]*ct[a[i]/dpri[j]];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
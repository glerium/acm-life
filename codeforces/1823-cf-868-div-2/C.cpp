#include <bits/stdc++.h>
using namespace std;
const int maxn=1007;
int t,n,a[maxn],prime[1000007],ctpri;
bool notpri[10000007];
void init(){
    notpri[1]=true;
    notpri[2]=false;
    for(int i=1;i<=1e7;i++) {
        if(!notpri[i]) {
            prime[++ctpri]=i;
            for(int j=i+i;j<=1e7;j+=i)
                notpri[j]=true;
        }
    }
}
int main(){
    init();
    // cout<<ctpri<<endl;
    cin>>t;
    while(t--){
        cin>>n;
        map<int,int> mp;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(!notpri[a[i]]) {
                if(mp.count(a[i])) mp[a[i]]++;
                else mp.insert(make_pair(a[i],1));
            }else{
                for(int j=1;j<=ctpri&&a[i]!=1;j++) {
                    while(a[i]%prime[j]==0) {
                        a[i]/=prime[j];
                        if(mp.count(prime[j])) mp[prime[j]]++;
                        else mp.insert(make_pair(prime[j],1));
                    }
                }
            }
        }
        int divct=0,ans=0;
        for(auto i : mp) {
            // printf("mp: %d %d\n",i.first,i.second);
            ans+=i.second/2;
            divct+=i.second%2;
        }
        ans+=divct/3;
        cout<<ans<<endl;
    }
    return 0;
}
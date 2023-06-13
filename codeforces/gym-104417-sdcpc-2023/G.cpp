#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int t,n;
ll a[maxn];
map<int,vector<ll>> mp;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        mp.clear();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) {
            if(mp.count(a[i]-i)) {
                mp[a[i]-i].push_back(a[i]);
            }else{
                mp.insert(make_pair(a[i]-i,vector<ll>()));
                mp[a[i]-i].push_back(a[i]);
            }
        }
        ll ans=0;
        for(auto i : mp) {
            auto v = i.second;
            sort(v.begin(),v.end(),greater<ll>());
            int ct=v.size();
            for(int i=0,j=1;j<ct;i+=2,j+=2) {
                if(v[i]+v[j]>0) ans+=v[i]+v[j];
                else break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
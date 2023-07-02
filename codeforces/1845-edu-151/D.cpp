#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int t,n,a[maxn],s[maxn];
set<int> st;
map<int,int> mp;
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        st.clear();
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        ll ans=LLONG_MIN, ansk=1919810;
        for(int i=n;i>=0;i--) {   // pos to reach k
            ll cur = 0;
            auto found = upper_bound(st.begin(),st.end(),s[i]);
            if(found==st.end()) {
                cur=s[i];
            }else{
                cur=s[i]+s[n]-mp[*found];
            }
            cout<<i<<' '<<cur<<endl;
            if(ans<cur) {
                ans=cur;
                ansk=s[i];
            }
            if(!st.count(s[i])) {
                st.insert(s[i]);
                mp[s[i]]=i;
            }
        }
        cout<<ansk<<endl;
    }
    return 0;
}
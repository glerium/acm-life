#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int t,n,idx,ct[maxn],r[maxn],s[maxn];
vector<int> a,b;
set<int> st;
map<int,int> mp,ans;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        a.clear();
        b.clear();
        idx=0;
        mp.clear();
        st.clear();
        ans.clear();
        for(int i=1,tmp;i<=n;i++) {
            cin>>tmp;
            a.push_back(tmp);
            s[i]=ct[i]=r[i]=0;
        }
        b=a;
        sort(b.begin(), b.end());
        for(auto i:b) st.insert(i);
        for(auto i:st) {
            idx++;
            mp[i]=idx;
        }
        vector<int> kk;
        kk.push_back(0);
        for(auto i:st) kk.push_back(i);
        for(int i=0;i<a.size();i++) r[i]=mp[a[i]];
        for(auto i:a) ct[mp[i]]++;
        int i=1,now=1,tttt=0;
        long long s=0;
        // for(auto i:mp) cout<<":"<<i<<endl;
        for(auto ii:kk) {
            if(ii==0) continue;
            if(now==i) {
                s += 1ll*ii*ct[mp[ii]];
                now++;
                tttt+=ct[mp[ii]];
                while(s>=kk[now]&&now<kk.size()) {
                    s += 1ll*kk[now]*ct[mp[kk[now]]];
                    tttt+=ct[mp[kk[now]]];
                    now++;
                }
            }
            ans[ii]=tttt-1;
            i++;
        }
        for(auto i:a) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}
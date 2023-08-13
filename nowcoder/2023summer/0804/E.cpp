#include <bits/stdc++.h>
#define yes puts("YES")
#define no puts("NO")
using namespace std;
const int maxn=1e5+10;
int t,n,q,s[maxn],s1[maxn],s2[maxn];
bool p[maxn];
long long a[maxn];
set<int> st;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        s[0]=0;
        st.clear();
        int first=-1,second=-1;
        for(int i=1;i<=n;i++) {
            s[i]=s[i-1]+(a[i]&1);
            p[i]=s[i]&1;
            if(a[i]&1) {
                if(!first) first=i;
                else if(!second) second=i;
                st.insert(i);
            }
        }
        for(int i=1;i<first;i++) s1[i]=i;
        for(int i=1;i<second;i++) s2[i]=i;
        bool in=false;
        for(int i=first;i<=n;i++) {
            if(in&&!a[i]) s1[i]=s1[i-1];
            else if(in&&a[i]) s1[i]=s1[i-1], in=false;
            else if(!in&&!a[i]) s1[i]=s1[i-1]+1;
            else if(!in&&a[i]) s1[i]=s1[i-1], in=true;
        }
        in=false;
        for(int i=second;i<=n;i++) {
            if(in&&!a[i]) s2[i]=s2[i-1];
            else if(in&&a[i]) s2[i]=s2[i-1], in=false;
            else if(!in&&!a[i]) s2[i]=s2[i-1]+1;
            else if(!in&&a[i]) s2[i]=s2[i-1], in=true;
        }
        // for(auto i :st) cout<<i<<' ';
        for(int i=1;i<=q;i++) {
            int l,r,k;
            cin>>l>>r>>k;
            if(k-1>r-l) no;
            else if((s[r]-s[l-1])%2!=0) no;
            else if(s[r]==s[l-1]) yes;
            else {
                auto nxtp = lower_bound(st.begin(), st.end(), l);
                int nxt = nxtp!=st.end() ? *nxtp : l;
                auto befp = lower_bound(st.rbegin(), st.rend(), r,greater<int>());
                int bef = befp!=st.rend() ? *befp : r;
                cout<<nxt<<' '<<bef<<endl;
                int t;
                if(p[nxt]) {
                    t = (nxt-l) + (s1[r]-s1[l-1]) + (r-bef);
                }else{
                    t = (nxt-l) + (s2[r]-s2[l-1]) + (r-bef);
                }
                cout<<t<<endl;
                if(t>=k-1) yes;
                else no; 
            }
        }
    }
}
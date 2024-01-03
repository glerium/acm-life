#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=2e5+10;
int t,n;
long long a[maxn];
set<long long> st;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        st.clear();
        st.insert(0);
        for(int i=1;i<=n;i++) cin>>a[i];
        long long now=0;
        bool ok=false;
        for(int i=1;i<=n;i++) {
            if(i&1) now+=a[i];
            else now-=a[i];
            ok|=st.count(now);
            st.insert(now);
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}
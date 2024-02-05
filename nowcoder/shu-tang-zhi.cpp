#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e6+10;
int n,a[maxn];
multiset<int> st;
bool check() {
    for(int i=2;i<=n;i++) if(a[i]!=a[1]) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(check()) {
        cout<<1<<endl;
        return 0;
    }
    int l=1,r=1,ans=1;
    st.insert(a[1]);
    while(l<n&&r<n) {
        // cout<<l<<' '<<r<<endl;
        // cout<<":"<<a[r+1]<<' '<<st.count(a[r+1])<<endl;
        if(!st.count(a[r+1])) {
            st.insert(a[r+1]);
            r++;
            if(r>n) break;
            ans=max(ans,r-l+1);
        }else{
            while(l<=n&&a[l]!=a[r+1]) {
                st.erase(a[l]);
                l++;
                if(l==r) break;
            }
            st.erase(a[l]);
            l++;
            if(l>r) r=l;
            st.insert(a[r]);
            if(l>n) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
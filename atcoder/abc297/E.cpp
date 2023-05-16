#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[100],ct;
ll pri[2000007];
set<ll> st;
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) st.insert(a[i]);
    for(int i=1;i<=k+10;i++) {
        pri[++ct]=*st.begin();
        st.erase(st.begin());
        for(int j=1;j<=n;j++) st.insert(pri[ct]+a[j]);
    }
    cout<<pri[k]<<endl;
    return 0;
}
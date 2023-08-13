#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,a[maxn];
int main() {
    long long sta = time(0);
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long ans=0;
    bool allsame = a[1]==1;
    for(int i=1;i<n;i++) {
        if(a[i]!=a[i+1])
            allsame = false;
    }
    if(allsame) {
        cout<<1ll*n*(n+1)/2<<endl;
        return 0;
    }
    multiset<int> st;
    for(int i=1;i<=n;i++) {
        st.clear();
        for(int j=i;j<=n;j++){
            if(a[j]==1) st.insert(a[j]),ans++;
            else{
                if(st.count(a[j]-1)) {
                    st.erase(st.find(a[j]-1));
                    st.insert(a[j]);
                    ans++;
                }else break;
            }
        }
    }
    cout<<(time(0)-sta)<<endl;
    return 0;
}
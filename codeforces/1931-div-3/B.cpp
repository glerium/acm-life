#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=2e5+10;
int t,n,a[maxn];
set<int> st;
void solve() {
    st.clear();
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s=0;
    for(int i=1;i<=n;i++) s+=a[i];
    s/=n;
    for(int i=1;i<=n;i++) {
        if(a[i]<s)
            st.insert(i);
    }
    for(int i=1;i<=n;i++) {
        if(a[i]<s) {
            puts("No");
            goto end;
        }else if(a[i]==s) continue;
        else {
            auto j=st.begin();
            while(a[i]>s) {
                int tmp=min(s-a[*j],a[i]-s);
                a[i]-=tmp; a[*j]+=tmp;
                int befj=*j;
                if(a[*j]>=s) {j++; st.erase(befj);}
                else j++;
            }
        }
    }
    if(st.empty()) puts("Yes");
    else puts("No");
end:;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) solve();
}
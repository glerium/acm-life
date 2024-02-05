#include <bits/stdc++.h>
#define yes puts("misaka")
#define no puts("ham")
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
ll n,m,a[maxn];
unordered_multiset<ll> st;
void dfs(int x) {
    if(st.count(x)) {
        st.erase(st.find(x));
        return;
    }
    if(x==1) return;
    dfs(x/2);
    dfs(x-x/2);
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    ll s=0;
    for(int i=1;i<=m;i++) s+=a[i];
    if(s!=n) {
        no;
        return 0;
    }
    for(int i=1;i<=m;i++) st.insert(a[i]);
    dfs(n);
    if(st.empty()) yes;
    else no;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll p=19491001;
int n,m,ans,ct_update_step,max_step;
ll a[10][10],b[10][10],target;
map<ll,int> st;
ll hashh(decltype(a) t = a) {
    ll hs=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            hs=hs*p+t[i][j];
    }
    return hs;
}
int dfs(int step) {
    static int ff=0;
    max_step=max(step,max_step);
    ff++;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++) 
    //         cout<<a[i][j]<<' ';
    //     cout<<endl;
    // }
    for(int i=1;i<n;i++) {
        for(int j=1;j<=m;j++) 
            swap(a[i][j],a[i+1][j]);
        ll hss=hashh();
        if(!st.count(hss)||st[hss]>step+1) {
            if(st[hss]>step+1) ct_update_step++;
            if(st.count(hss)) st.erase(hss);
            st.insert({hss, step+1});
            dfs(step+1);
        }
        for(int j=1;j<=m;j++) 
            swap(a[i][j],a[i+1][j]);
    }
    for(int j=1;j<m;j++) {
        for(int i=1;i<=n;i++) 
            swap(a[i][j],a[i][j+1]);
        ll hss=hashh();
        if(!st.count(hss)||st[hss]>step+1) {
            if(st[hss]>step+1) ct_update_step++;
            if(st.count(hss)) st.erase(hss);
            st.insert({hss, step+1});
            dfs(step+1);
        }
        for(int i=1;i<=n;i++) 
            swap(a[i][j],a[i][j+1]);
    }
    return ff;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
    target=hashh(b);
    st[hashh()]=0;
    dfs(0);
    cout<<dfs(0)<<' '<<st.size()<<endl;
    clog<<"updated step: "<<ct_update_step<<endl;
    clog<<"Max step: "<<max_step<<endl;
    if(st.count(target)) 
        cout<<st[target];
    else cout<<-1;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll p=19491001;
int n,m,ans;
ll a[10][10],b[10][10];
set<vector<int>> inq;
map<vector<int>,int> st;
struct State{
    vector<int> now;
    int step;
    bool operator<(const State& rhs) const{
        return step>rhs.step;
    }
};
priority_queue<State> q;
vector<int> flat(decltype(a) t=a) {
    vector<int> ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans.push_back(t[i][j]);
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
    auto target=flat(b);
    st[flat(a)]=0;
    q.push({flat(a),0});
    // int ct=0;
    while(!q.empty()) {
        // ct++;
        auto top=q.top(); q.pop();
        if(st[top.now]!=top.step) continue;
        ll a[10][10]={};
        int idx=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++)
                a[i][j]=top.now[idx++];
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<=m;j++) 
                swap(a[i][j],a[i+1][j]);
            auto ttt=flat(a);
            if(!st.count(ttt)||st[ttt]>top.step+1) {
                st[ttt]=top.step+1;
                q.push({ttt,top.step+1});
            }
            for(int j=1;j<=m;j++) 
                swap(a[i][j],a[i+1][j]);
        }
        for(int j=1;j<m;j++) {
            for(int i=1;i<=n;i++) 
                swap(a[i][j],a[i][j+1]);
            auto ttt=flat(a);
            if(!st.count(ttt)||st[ttt]>top.step+1) {
                st[ttt]=top.step+1;
                q.push({ttt,top.step+1});
            }
            for(int i=1;i<=n;i++) 
                swap(a[i][j],a[i][j+1]);
        }
    }
    // cout<<ct<<endl;
    if(st.count(target)) cout<<st[target];
    else cout<<-1;
    return 0;
}
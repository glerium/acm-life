#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
using namespace std;
constexpr int maxn=2e5+10;
int t,n,m,k;
set<int> a,b;
int get_intc(set<int>a,set<int>b) {
    set<int> st;
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(st,st.begin()));
    return st.size();
}
int get_unionc(set<int>a,set<int>b) {
    set<int> st;
    set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(st,st.begin()));
    return st.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        a.clear(); b.clear();
        rep(i,1,n) {
            int tmp; cin>>tmp;
            if(tmp<=k) a.insert(tmp);
        }
        rep(i,1,m) {
            int tmp; cin>>tmp;
            if(tmp<=k) b.insert(tmp);
        }
        int intc=get_intc(a,b);
        int unionc=get_unionc(a,b);
        if(a.size()-intc>k/2) {no; continue;}
        else if(b.size()-intc>k/2) {no; continue;}
        else if(unionc<k) {no; continue;}
        else {yes; continue;}
    }
    return 0;
}
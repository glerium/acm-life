#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e5+10;
int t,n,a[maxn],b[maxn],c[maxn];
struct Sort{
    int i,v;
    bool operator<(const Sort& rhs)const{
        return v>rhs.v;
    }
}aa[maxn],bb[maxn],cc[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        rep(i,1,n) (cin>>a[i]),aa[i].i=i,aa[i].v=a[i];
        rep(i,1,n) (cin>>b[i]),bb[i].i=i,bb[i].v=b[i];
        rep(i,1,n) (cin>>c[i]),cc[i].i=i,cc[i].v=c[i];
        sort(aa+1,aa+1+n);
        sort(bb+1,bb+1+n);
        sort(cc+1,cc+1+n);
        set<int> st;
        for(int i=1;i<=3;i++) st.insert(a[i]);
        for(int i=1;i<=3;i++) st.insert(b[i]);
        for(int i=1;i<=3;i++) st.insert(c[i]);
        
    }
}
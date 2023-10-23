#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
int _,n,real_to_idx[maxn],idx,t[maxn];
set<int> st;
struct Segment{
    int l,r;
}a[maxn];
int lowbit(int x) {return x&-x;}
void add(int x,int k) {
    while(x<=n) {
        t[x]+=k;
        x+=lowbit(x);
    }
}
ll sum(int x) {
    ll ret=0;
    while(x<=n) {
        ret+=t[x];
        x-=lowbit(x);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n;
        st.clear();
        rep(i,1,n) {
            cin>>a[i].l>>a[i].r;
            st.insert(a[i].l);
            st.insert(a[i].r);
        }
        st.insert(1);
        st.insert(n);
        for(auto i:st) real_to_idx[++idx]=i;
        rep(i,1,n) {
            a[i].l=real_to_idx[a[i].l];
            a[i].r=real_to_idx[a[i].r];
        }
        rep(i,1,n) add(a[i].l, a[i].r);
        int m=st.size();
        rep(i,1,m) {
            
        }
    }
}
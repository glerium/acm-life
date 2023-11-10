#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=2e5+10;
int _,n,head[maxn],cnt;
set<pair<int,int>> st;
bitset<maxn> v;
struct Edge{
    int to,nxt;
}a[maxn<<1];
void add(int x,int y){
    a[++cnt]={y,head[x]};
    head[x]=cnt;
}
bool dfs(int x) {
    // cout<<x<<endl;
    bool loop=true;
    int ct=0;
    v[x]=true;
    for(int i=head[x];i;i=a[i].nxt) {
        ct++;
        if(v[a[i].to]) continue;
        loop &= dfs(a[i].to);
    }
    loop &= (ct==2);
    return loop;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n;
        cnt=0;
        st.clear();
        for(int i=1;i<=n;i++) v[i]=false, head[i]=0;
        for(int i=1;i<=n;i++) {
            int tmp; cin>>tmp;
            if(st.count(make_pair(i,tmp))) continue;
            add(i,tmp); add(tmp,i);
            st.insert({i,tmp}); st.insert({tmp,i});
        }
        int blocks=0, loops=0;
        for(int i=1;i<=n;i++) {
            if(!v[i]) {
                blocks++;
                loops+=dfs(i);
            }
        }
        cout<<min(blocks,loops+1)<<' '<<blocks<<endl;
    }
    return 0;
}
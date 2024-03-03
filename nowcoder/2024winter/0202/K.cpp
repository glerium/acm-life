#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn=2e5+10;
constexpr ll mod=998244353;
int n,heada[maxn],headb[maxn],cta,ctb,in[maxn],to[maxn],dep[maxn],fa[maxn],idx,ord[maxn];
ll ans=1;
char choice[maxn];
string c[maxn];
bitset<maxn> v, isloop, v2;
vector<int> all, loop;
stack<int> q;
set<array<int,2>> st;
struct Edge{
    int to,nxt;
}a[maxn],b[maxn];

void add1(int x, int y) {
    a[++cta]={y,heada[x]};
    heada[x]=cta;
}
void add2(int x, int y) {
    if(st.count({x,y})) return;
    st.insert({x,y});
    b[++ctb]={y,headb[x]};
    headb[x]=ctb;
}
void dfs1(int x, int from) {      // 第一次dfs找环，在b上操作
    fa[x] = from;
    v[x] = true;
    dep[x]=++idx;
    for(int i = headb[x]; i; i=b[i].nxt) {
        if(to[to[x]] == x) {
            isloop[x] = isloop[to[x]] = true;
            v[to[x]] = true;
            loop.push_back(x);
            loop.push_back(to[x]);
            return;
        }
        if(b[i].to == from) continue;
        if(!v[b[i].to])
            dfs1(b[i].to, x);
        else if(dep[b[i].to] <= dep[x] && !isloop[b[i].to]) {
            for(int j=x; ; j=fa[j]) {
                isloop[j] = true;
                loop.push_back(j);
                if(j == b[i].to) break;
            }
        }
    }
}
bool dfs2(int loopend) {        // 第二次dfs，求解答案
    v2[loopend] = true;
    int ima = loopend;
    while(!v2[to[ima]]) {
        v2[ima] = true;
        choice[to[ima]] = c[ima][choice[ima] - 'A'];
        ima = to[ima];
    }
    if(choice[to[ima]] != c[ima][choice[ima] - 'A'])
        return false;
    else
        return true;
}
bool cmp(int x,int y) {
    return in[x] < in[y];
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) {
        int tmp; cin>>tmp>>c[i];
        add1(i,tmp);
        add2(i,tmp);
        add2(tmp,i);
        in[tmp]++;
        to[i]=tmp;
    }
    for(int i=1;i<=n;i++) ord[i]=i;
    sort(ord+1, ord+1+n, cmp);
    for(int ii=1;ii<=n;ii++) {
        int i=ord[ii];
        if(!v[i]) {
            all.clear(); loop.clear();
            if(to[i]==i) {
                v[i] = true;
                isloop[i] = true;
                loop.push_back(i);
            }else if(to[to[i]] == i) {
                v[i] = v[to[i]] = true;
                isloop[i] = isloop[to[i]] = true;
                loop.push_back(i);
                loop.push_back(to[i]);
            } else {
                dfs1(i, -1);
            }
            if(loop.empty()) {
                if(to[i] == i) {
                    int ct = 0;
                    for(int j=0;j<5;j++) ct+=c[i][j] == (j+'A');
                    ans = ans * ct % mod;
                }
                continue;
            }
            int loopend=loop[0];
            int ct = 0;
            for(char op='A'; op<='E'; op++) {
                choice[loopend] = op;
                for(auto j:loop)
                    v2[j] = false;
                bool ima = dfs2(loopend);
                ct += ima;
            }
            ans = ans * ct % mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e5+10;
int n,m,ct,head[maxn],pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
vector<int> bcc[maxn];
struct Edge {
    int to, nxt;
}a[maxn<<1];
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
stack<pair<int,int>> stk;
int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i=head[u];i;i=a[i].nxt) {
        int v = a[i].to;
        pair<int,int> e = {u,v};
        if(!pre[v]) {
            stk.push(e);
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowv, lowu);
            if(lowv >= pre[u]) {
                iscut[u] = true;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                while(true) {
                    auto x = stk.top(); stk.pop();
                    if(bccno[x.first] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.first);
                        bccno[x.first] = bcc_cnt;
                    }
                    if(bccno[x.second] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.second);
                        bccno[x.second] = bcc_cnt;
                    }
                    if(x.first == u && x.second == v)
                        break;
                }
            }
        } else if(pre[v] < pre[u] && v != fa) {
            stk.push(e);
            lowu = min(lowu, pre[v]);
        }
    }
    if(fa < 0 && child == 1)
        iscut[u] = 0;
    return lowu;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testc = 0;
    cin >> m;
    while(m) {
        ct = n = dfs_clock = bcc_cnt = 0;
        memset(head, 0, sizeof(head[0]) * (m+5));
        testc++;
        for(int i=1;i<=m;i++){
            int x,y; cin>>x>>y;
            add(x, y);
            add(y, x);
            n = max({n, x, y});
        }
        memset(pre, 0, sizeof(pre[0]) * (n+5));
        memset(iscut, 0, sizeof(iscut[0]) * (n+5));
        memset(bccno, 0, sizeof(bccno[0]) * (n+5));
        for(int i=1;i<=n;i++) {
            if(!pre[i])
                dfs(i, -1);
        }
        ll ans1 = 0, ans2 = 1;
        if(bcc_cnt == 1) {
            ans1 = 2;
            ans2 = 1ll * n * (n-1) / 2;
        }else{
            for(int i=1;i<=bcc_cnt;i++) {
                int cut_ct = 0;
                for(int j : bcc[i]) {
                    if(iscut[j])
                        cut_ct++;
                }
                if(cut_ct == 1) {
                    ans1++;
                    ans2 *= bcc[i].size() - 1;
                }
            }
        }
        cout << "Case " << testc << ": " << ans1 << ' ' << ans2 << endl;
        cin >> m;
    }
    return 0;
}

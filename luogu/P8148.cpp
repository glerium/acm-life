#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
int a[maxn];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

void solve() {
    int n = read();
    int m = n * (n+1) / 2;
    vector<int> a(m+5);
    rep(i,1,m) a[i] = read();
    sort(a.begin() + 1, a.begin() + 1 + m);
    unordered_map<int,int> st;
    rep(i,1,m) st[a[i]]++;
    int idx = 1;
    vector<int> ans;
    while(!st.empty() && ans.size() < n) {
        while(st[a[idx]] == 0)
            idx++;
        int tmp = a[idx];
        ans.push_back(tmp);
        if(ans.size() == n) break;

        int now = tmp;
        st[tmp]--;
        for(int i=ans.size()-2;i>=0;i--) {
            now += ans[i];
            st[now]--;
        }
    }
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
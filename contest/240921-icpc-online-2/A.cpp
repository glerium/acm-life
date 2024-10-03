#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll c[100005];
set<int> st;
map<string, int> mp;
int ct;
vector<int> v[100005];
struct Team {
    ll w; 
    string s; 
}tt[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>c[i];
    for(int i=1;i<=n;i++) {
        int w; string s; cin >> w >> s;
        tt[i].w = w; tt[i].s = s;
        if(!mp.count(s))
            mp[s] = ++ct;
        v[mp[s]].push_back(w);
    }
    for(int i=1;i<=ct;i++)
        sort(v[i].begin(), v[i].end(), greater<int>());
    ll mc = 0x3f3f3f3f;
    for(int i=1;i<=k;i++)
        mc = min(mc, c[i]);
    for(int i=1;i<=ct;i++) {
        for(int j=0;j<min(ll(v[i].size()), mc); j++) {
            st.insert(v[i][j]);
        }
    }
    vector<int> q;
    for(auto i : st)
        q.push_back(i);
    sort(q.begin(), q.end(), greater<int>());
    for(int i=1;i<=n;i++) {
        int l=0, r=q.size()-1, mid, ans;
        ll target = tt[i].w;
        if(target < q[q.size()-1]) {
            cout << q.size() << endl;
            continue;
        }
        while(l <= r) {
            mid = (l + r) >> 1;
            if(q[mid] >= target) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        ans++;                          // 大于等于它的个数
        if(st.count(target)) ans--;     // 大于它的个数
        ans++;                          // 它的排名
        int school = mp[tt[i].s];
        int sr = min(ll(v[school].size()), mc);
        if(tt[i].w < v[school][sr-1])
            ans--;
        cout << ans << endl;
    }
    return 0;
}
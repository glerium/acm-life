#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
constexpr int maxn = 7373;
int n;
vector<int> a[maxn];
struct State {
    int sum;
    int x,y;
    bool operator<(const State& rhs)const{
        return sum > rhs.sum;
    }
};
vector<int> merge(vector<int> &va, vector<int> &vb) {
    priority_queue<State> q;
    q.push({va[0] + vb[0], 0, 0});
    int k = n;
    vector<int> ret;
    set<pair<int,int>> st;
    st.insert({0,0});
    while(k--) {
        auto now = q.top(); q.pop();
        ret.push_back(now.sum);
        if(now.x+1 < n && !st.count({now.x+1, now.y})) {
            q.push({va[now.x+1] + vb[now.y], now.x+1, now.y});
            st.insert({now.x+1, now.y});
        }
        if(now.y+1 < n && !st.count({now.x, now.y+1})) {
            q.push({va[now.x] + vb[now.y+1], now.x, now.y+1});
            st.insert({now.x, now.y+1});
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n) {
        for(int i=0;i<n;i++) {
            a[i].clear();
            for(int j=0,tmp;j<n;j++) {
                cin >> tmp;
                a[i].push_back(tmp);
            }
            sort(a[i].begin(), a[i].end());
        }
        vector<int> now = merge(a[0], a[1]);
        for(int i=2;i<n;i++)
            now = merge(now, a[i]);
        for(int i=0;i<n;i++)
            cout << now[i] << " \n"[i == n-1];
    }
    return 0;
}

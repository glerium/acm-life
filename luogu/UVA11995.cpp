#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    if(cin.eof()) exit(0);
    bool is_stk = true, is_q = true, is_pq = true;
    stack<int> stk;
    queue<int> q;
    priority_queue<int> pq;
    vector<int> ans_stk, ans_q, ans_pq;
    vector<int> ans;
    for(int i=1;i<=n;i++) {
        int op,x; cin >> op >> x;
        if(op == 1) {
            stk.push(x);
            q.push(x);
            pq.push(x);
        }else{
            ans.push_back(x);
            if(stk.empty())
                is_stk = false;
            else {
                int ima = stk.top(); stk.pop();
                ans_stk.push_back(ima);
            }
            if(q.empty())
                is_q = false;
            else {
                int ima = q.front(); q.pop();
                ans_q.push_back(ima);
            }
            if(pq.empty())
                is_pq = false;
            else {
                int ima = pq.top(); pq.pop();
                ans_pq.push_back(ima);
            }
        }
    }
    is_stk &= ans_stk == ans;
    is_q &= ans_q == ans;
    is_pq &= ans_pq == ans;
    // for(auto i : ans_pq) cout << i << ' ';
    // cout << endl;
    if(is_stk + is_q + is_pq == 1) {
        if(is_stk) cout << "stack" << endl;
        else if(is_q) cout << "queue" << endl;
        else cout << "priority queue" << endl;
    } else if(!is_stk && !is_q && !is_pq)
        cout << "impossible" << endl;
    else
        cout << "not sure" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true)
        solve();
    return 0;
}

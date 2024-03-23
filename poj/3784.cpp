/// 模板题：两个set维护中位数

#include <iostream>
#include <vector>
#include <queue>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
const ll mod = 998244353;
void solve() {
    int tc, n; cin >> tc >> n;
    cout << tc << ' ' << n / 2 + 1 << endl;
    priority_queue<int, vector<int>, greater<int> > q1;      // min -> mid (+1)
    priority_queue<int, vector<int>, less<int> > q2;         // max -> mid
    vector<int> v(n+5);
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) {
        int tmp = v[i];
        if(q1.empty() || tmp >= q1.top())
            q1.push(tmp);
        else
            q2.push(tmp);
        if(q1.size() < (i+1)/2) {
            int tt = q2.top();
            q2.pop();
            q1.push(tt);
        }
        if(q1.size() > (i+1)/2) {
            int tt = q1.top();
            q1.pop();
            q2.push(tt);
        }
        int ct = i / 2 + 1;
        if(i&1) cout << q1.top() << " \n"[ct%10==0];
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

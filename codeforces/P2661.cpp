#include <bits/stdc++.h>
using namespace std;
int n, a[200005], ans=0x3f3f3f3f, v[200005], instk[200005];
stack<int> stk;
bool dfs(int x) {
    if(instk[a[x]]) {
        int cur = 1;
        while(stk.top() != a[x]) {
            cur++;
            instk[stk.top()] = false;
            stk.pop();
        }
        instk[stk.top()] = false;
        stk.pop();
        ans = min(ans, cur);
        return false;
    }else if(!v[a[x]]) {
        v[a[x]] = true;
        instk[a[x]] = true;
        stk.push(a[x]);
        bool sts = dfs(a[x]);
        if(!sts)
            return false;
        stk.pop();
        instk[a[x]] = false;
        return true;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++) {
        if(!v[i]) {
            while(!stk.empty()) {
                instk[stk.top()] = false;
                stk.pop();
            }
            stk.push(i);
            v[i] = true;
            instk[i] = true;
            dfs(i);
            instk[i] = false;
        }
    }
    cout << ans << endl;
}
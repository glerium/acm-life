#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int check(char x, char y) {
    if(x == '(' && y == ')' ||
       x == '[' && y == ']' ||
       x == '<' && y == '>')
        return true;
    else return false;
}
void solve() {
    string s; cin >> s;
    stack<char> stk;
    for(auto i : s) {
        if(i == ')' || i == ']' || i == '>') {
            if(stk.empty() || !check(stk.top(), i)) {
                cout << "No" << endl;
                return;
            }else{
                stk.pop();
            }
        }else stk.push(i);
    }
    if(stk.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}

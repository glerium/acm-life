#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    stack<char> stk;
    for(auto ch : s) {
        if(ch != ')') stk.push(ch);
        else {
            string s;
            while(stk.top() != '(') {
                s += stk.top();
                stk.pop();
            }
            stk.pop();
            reverse(s.begin(), s.end());
            cout << s << endl;
        }
    }
}
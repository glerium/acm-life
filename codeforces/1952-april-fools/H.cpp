#include <bits/stdc++.h>
using namespace std;
string s[107];
bool check(string s) {
    int l = 0, r = s.size() - 1;
    while(l < r) {
        if(s[l] != s[r])
            return false;
        l++, r--;
    }
    return true;
}
int main() {
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        string ss; cin >> ss;
        for(int j=0;j<ss.size();j++)
            s[j+1] += ss[j];
    }
    for(int i=1;i<=t;i++)
        puts(check(s[i]) ? "YES" : "NO");
}
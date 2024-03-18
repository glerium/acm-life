#include <bits/stdc++.h>
using namespace std;
int n;
map<string, int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while(n) {
        for(int i=1;i<=n;i++) {
            string s; cin >> s;
            mp[s]++;
        }
        string ans;
        int ct = 0;
        for(auto i : mp) {
            if(i.second > ct) {
                ans = i.first;
                ct = i.second;
            }
        }
        cout << ans << endl;
        cin >> n;
        mp.clear();
    }
    return 0;
}
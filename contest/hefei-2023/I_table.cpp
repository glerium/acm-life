#include <bits/stdc++.h>
using namespace std;
vector<int> mp;
string cvt(int x, int k) {
    string s;
    while(x) {
        int c = x % k;
        s.push_back(mp[c]);
        x /= k;
    }
    if(s.size())
        s = string(s.rbegin(), s.rend());
    else
        s = mp[0];
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    for(int n=2;n<=52;n++) {
        for(int i=0;i<n;i++) {
            if(i < 26) mp.push_back('a' + i);
            else mp.push_back('A' - 26 + i);
        }
        srand(time(0));
        random_shuffle(mp.begin(), mp.end());

        int ct[n][2] = {};
        vector<string> s;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                s.push_back(cvt(i*j, n));
            }
        }
        for(auto i : s) {
            for(int j = 0; j < i.size();j ++)
                ct[i[j]-'a'][j]++;
        }
        set<pair<int,int>> ss;
        for(int i=0;i<n;i++)    ss.insert({ct[i][0], ct[i][1]});
        if(ss.size() != n) cout << "!!" << n << endl;
    }
}
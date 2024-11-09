#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p,k; cin >> p >> k;
    string s;
    for(int i=1;i<=p;i++) {
        string tmp;
        cin >> tmp;
        s += tmp;
    }
    int n = s.size();
    vector<string> words;
    int wc; cin >> wc;
    for(int i=1;i<=wc;i++) {
        string str; cin >> str;
        bool flag = true;
        for(auto j : words) {
            if(j.substr(0, str.size()) == str)
                flag = false;
        }
        if(flag)
            words.push_back(str);
    }
    int f[n+5] = {};
    int ct = 0;
    for(int i=0;i<n;i++) {
        for(auto j : words) {
            if(s.substr(i, j.size()) == j) {
                ct++;
                for(int k=i;k<i+j.size()-1;k++)
                    f[k]++;
            }
        }
    }
    sort(f, f+n-1);     // 0 .. n-2
    for(int i=0;i<=k;i++)
        ct -= f[i];
    cout << ct << endl;
    return 0;
}

// abc bcd
// abcd
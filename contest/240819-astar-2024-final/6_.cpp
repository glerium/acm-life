#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
bool check() {
    if(v.size() == 0) return false;
    int mx = max_element(v.begin(), v.end()) - v.begin();
    for(int i=0;i<mx;i++) {
        if(v[i] >= v[i+1]) return false;
    }
    for(int i=mx;i<v.size()-1;i++) {
        if(v[i] <= v[i+1]) return false;
    }
    return true;
}
int main() {
    cin >> n;
    int a[n+5];
    for(int i=0;i<n;i++) cin >> a[i];
    int ct = 0;
    for(int i=0;i<(1<<n);i++) {
        v.clear();
        for(int j=0;j<n;j++) {
            if(i&(1<<j)) v.push_back(a[j]);
        }
        ct += check();
    }
    cout << ct;
    return 0;
}
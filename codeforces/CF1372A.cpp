#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        set<int> st;
        int now = 1;
        for(int i=1;i<=n;i++) {
            while(st.count(now)) now++;
            cout << now << ' ';
        }
        cout << endl;
    }
}
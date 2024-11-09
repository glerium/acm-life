#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n,r1,c1,r2,c2,r3,c3;
        int x, y;
        cin>>n>>r1>>c1>>r2>>c2>>r3>>c3>>x>>y;
        multiset<int> str = {r1,r2,r3};
        int nr, nc, sr, sc;
        for(auto x:str) {
            if(str.count(x) == 2)  {
                sr = x;
            }else{
                nr = x;
            }
        }
        multiset<int> src = {c1,c2,c3};
        for(auto x:src) {
            if(src.count(x) == 2)  {
                sc = x;
            }else{
                nc = x;
            }
        }
        // cout << sr << sc << nr << nc << endl;
        if(x == sr || y == sc) {
            cout << "YES" << endl;
            continue;
        }

        set<pair<int,int>> st;
        st.insert({r1,c1});
        st.insert({r2,c2});
        st.insert({r3,c3});
        if(st.count({1,1}) && st.count({1,2}) && st.count({2,1}) ||
           st.count({n,n}) && st.count({n-1,n}) && st.count({n,n-1}) ||
           st.count({1,n}) && st.count({1,n-1}) && st.count({2,n}) ||
           st.count({n,1}) && st.count({n-1,1}) && st.count({n,2})) {
            if(st.count({x,y}))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        if((x-sr)%2==0 || (y-sc)%2==0) {
            cout << "YES" << endl;
            continue;
        }
        if((x-y)%2 == (sr-nc)%2 && (x-y)%4 != (sr-nc)%4) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
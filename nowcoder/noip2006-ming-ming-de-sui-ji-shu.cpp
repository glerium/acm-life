#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin>>m;
    set<int> st;
    for(int i=1;i<=m;i++) {
        int x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
    for(auto i : st) {
        cout<<i<<' ';
    }
}
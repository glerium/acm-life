#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n; cin >> n;
    int a[n+5][n+5]; 
    rep(i,1,n) rep(j,1,n) cin >> a[i][j];
    vector<int> vec;
    int x=1,y=1;
    rep(i,1,n) {
        if(i % 2 == 1) {
            rep(j,1,i-1) vec.push_back(a[j][i]);
            vec.push_back(a[i][i]);
            for(int j=i-1;j>=1;j--) vec.push_back(a[i][j]);
        }else{
            rep(j,1,i-1) vec.push_back(a[i][j]);
            vec.push_back(a[i][i]);
            for(int j=i-1;j>=1;j--) vec.push_back(a[j][i]);
        }
    }
    int ct = 0;
    for(int i=0;i<vec.size()-1;i++) {
        if(vec[i+1] > vec[i]) ct--;
        else ct++;
    }
    if(ct < 0) {
        for(int i=vec.size()-1;i>=0;i--) {
            cout << vec[i];
            if(i != 0) cout << ' ';
            else cout << "\n";
        }
    }else {
        for(int i=0;i<vec.size();i++) {
            cout << vec[i];
            if(i != vec.size()-1) cout << ' ';
            else cout << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
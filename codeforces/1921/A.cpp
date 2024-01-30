#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int _,n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>_;
    while(_--) {
        set<int> a,b;
        for(int i=1;i<=4;i++) {
            int x,y; cin>>x>>y;
            a.insert(x); b.insert(y);
        }
        cout<<abs((*a.begin()-*--a.end())*(*b.begin()-*--b.end()))<<endl;
    }
    return 0;
}
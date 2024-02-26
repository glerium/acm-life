#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int t,n,a[maxn];
set<char> r[maxn];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        s.clear();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<26;i++) r[0].insert('a'+i);
        for(int i=1;i<=n;i++) {
            auto tmp=*r[a[i]].begin();
            r[a[i]].erase(tmp);
            r[a[i]+1].insert(tmp);
            s+=tmp;
        }
        cout<<s<<endl;
    }
}
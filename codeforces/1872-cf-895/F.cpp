#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
const int maxn=1e5+10;
int _,n,a[maxn],c[maxn],d[maxn];
queue<int> q;
set<int> in,notin;
vector<int> ans;
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        while(!q.empty()) q.pop();
        in.clear();
        notin.clear();
        ans.clear();
        cin>>n;
        for(int i=1;i<=n;i++) d[i]=0;
        rep(i,1,n) {
            cin>>a[i];
            d[a[i]]++;
        }
        rep(i,1,n) cin>>c[i];
        rep(i,1,n) {
            if(!d[i]) {
                q.push(i);
                ans.push_back(i);
                in.insert(i);
            }
        }
        while(!q.empty()) {
            int cur=q.front();
            q.pop();
            d[a[cur]]--;
            if(!d[a[cur]]){
                q.push(a[cur]);
                ans.push_back(a[cur]);
                in.insert(a[cur]);
            }
        }
        rep(i,1,n) {
            if(!in.count(i)) 
                notin.insert(i);
        }
        while(!notin.empty()) {
            auto head = *(notin.begin());
            int mi=c[head], mii=head;
            for(int i=a[mii]; i!=mii; i=a[i]) {
                if(c[i]<mi) {
                    mi=c[i];
                    mii=i;
                }
            }
            for(int i=a[mii]; notin.count(i); i=a[i]){
                ans.push_back(i);
                notin.erase(i);
            }
        }
        for(auto i : ans) cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}
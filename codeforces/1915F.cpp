#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
constexpr int maxn=2e5+10;
tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> t;
int _,n;
struct People{
    int x;
    int y;
    bool operator<(const People& rhs)const{
        return x<rhs.x;
    }
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        t.clear();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
        sort(a+1,a+1+n);
        long long ans=0;
        for(int i=1;i<=n;i++) {
            ans+=t.order_of_key(a[i].y);
            t.insert(a[i].y);
        }
        cout<<ans<<endl;
    }
    return 0;
}
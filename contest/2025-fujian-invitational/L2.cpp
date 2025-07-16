#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
int main()
{
    int n = 4;
    int a[10] = {0,1,1,1,4};
    map<int,int> mp;
    rep(i,1,(1<<n)-1) {
        int mi = 114514, mx = -114514;
        rep(j,1,n) {
            if((1<<(j-1)) & i) {
                mi = min(mi, a[j]);
                mx = max(mx, a[j]);
                // cout << a[j] << ' ';
            }
        }
        // cout << endl;
        mp[mi+mx]++;
    }
    for(auto [x,y] : mp) {
        cout << x << ' ' << y << endl;
    }
    return 0;
}
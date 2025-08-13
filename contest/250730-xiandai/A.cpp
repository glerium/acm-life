#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int x,y; cin >> x >> y;
        int ans = 114514;
        rep(i,x-10,x+10) {
            rep(j,y-10,y+10) {
                if(i > j || i < 1 || j > 1e9) continue;
                if((j-i)%10 == (i+j)%10) {
                    ans = min(ans, abs(i-x)+abs(j-y));
                }
                
            }
        }
        cout << ans << endl;
    }
}
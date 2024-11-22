#include <bits/stdc++.h>
#define endl '\n'

#define rep(i, o, p) for(int i = o ; i <= p; i ++)
using namespace std;

void sol(){
    int a, b, c,d;
    cin >> a >> b >> c >> d;
    if(a < 4) {
        cout << 0 << endl;
        return;
    }
    int s = a + b + c + d;
    int ans = 0;
    for(int i=0;i<=1000;i++) {
        for(int j=0;j<=1000;j++) {
            if((i+2)*(j+2) > s || i * j > d) {
                break;
            }
            int sb, sc;
            if((i-j)%2 == 0) {
                sb = (i+1)/2*2 + j/2*2,
                sc = i/2*2 + (j+1)/2*2;
            }else{
                sb = i+j;
                sc = i+j;
            }
            if(sb < 0 || sc < 0)
                continue;
            if(sb <= b && sc <= c) {
                ans = max(ans, (i+2)*(j+2));
                // cout << sb << ' ' << sc << ' ' << i+2 << ' ' << j+2 << endl;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    rep(t, 1, T) {
        sol();
    }
    return 0;
}

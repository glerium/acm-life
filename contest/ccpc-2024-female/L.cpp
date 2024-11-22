#include <bits/stdc++.h>
#define endl '\n'

#define rep(i, o, p) for(int i = o ; i <= p; i ++)
using namespace std;

void sol(){
    int a, b, c,d;
    cin >> a >> b >> c >> d;
    if(a < 4) {
        cout << 0 << '\n'; 
        return ;
    }
    int maxl = 1500;
    int ans = 4;
    for(int i = 1; i <= maxl; i += 2){
        int nc = (i + 1) / 2 , nb = i / 2;
        if(nc * 2 > c || nb * 2 > b) break;
        int pc = c  - 2 * nc, pb = b - 2 * nb;
        pc /= 2, pb /= 2;
        int hb;
        if(pb > pc) {
            hb = pc * 2 + 1;
        }
        else hb = 2 * pb - 1;
        int hd = d/i;
        if(hd % 2 == 0) hd --;
        int tmp = min(hb, hd);
       if(tmp <= 0 ) continue;
        ans = max(ans, (2 + i) * (tmp + 2) );
    }
    for(int i = 2; i <= maxl; i += 2){
        int nc = i / 2, nb = i / 2;
        if(nc * 2 > c || nb * 2 > b) break;
        int pc = c - 2 * nc, pb = b - 2 * nb;
        pc /= 2, pb /= 2;
        int hb = min(pb, pc) * 2;
        int hd = d / i;
        if(hd % 2 == 1) hd --;
        int tmp = min(hb, hd);
       if(tmp <= 0 ) continue;
        ans = max(ans, (2 + i) * (tmp + 2) );
    }
    cout << ans << '\n';
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

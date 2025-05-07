#include <bits/stdc++.h>

#define rep(i,x,y) for(int i=x;i<=y;i++)

const int  N = 110;
const __int128 inf = 1e12 + 7;

#define ll __int128
#define realll long long

using namespace std;

realll n, p, h;

ll p1[N], p2[N];
ll tot1, tot2, tot3;
ll sum1 = 0, sum2 = 1;
ll s1[N], s2[N];

bool check(ll mid) {
    ll turn = mid / n, kp = mid % n;
    ll now_h= h;
    ll now = p;
    if(sum1 == 0 && now == 0 || tot3 == 0) return 0;
    if(sum2 == 1 ) {
        ll tmp1 = (p * 2 + (turn + 1) * sum1 );
        if(tmp1 > inf) tmp1 = inf;
        ll tmp2 =  tmp1 * turn / 2;
        if(tmp2 > inf) tmp2 = inf;
        now_h -= tmp2 * tot3;
        now += sum1 * turn; 
        if(now_h <= 0) return 1;
    }else {
        rep(i, 1, turn) {
            now = (now + sum1) * sum2;
            if(now > inf) now = inf;
            now_h -= now * tot3; 
            if(now_h <= 0) return 1;
        }
    }
    if(now > inf) now = inf;
    rep(i, 0, tot1) {
        rep(j, 0, tot2) {
                if(i + j > kp) continue;
                ll k = min(tot3, kp - i - j);
                // s1[i] s2[j] 
                ll tmp4 = (now + s1[i]) * s2[j] ;
                if(tmp4 > inf) tmp4 = inf;
                if(tmp4 * k >= now_h){
                    return true;
                }
            
        }
    }
    return 0;
}

void solve() {
    cin >> n >> p >> h;
    tot1 = tot2 = tot3 = 0;
    rep(i, 1, n) {
        char opt; 
        cin >> opt;
        if(opt == '*') {
            realll x;
            cin >> x;
            p2[++tot2] = x;
            sum2 *= x;
            if(sum2 > inf) sum2 = inf; 
        }
        if(opt == '+') {
            realll x;
            cin >> x;
            p1[++tot1] = x;
            sum1 += x;
            if(sum1 > inf) sum1 = inf; 
        }
        if(opt == '!') tot3 ++;
    }
    sort(p1 + 1, p1 + tot1 + 1);
    reverse(p1 + 1, p1 + tot1 + 1);
    sort(p2 + 1, p2 + tot2 + 1);
    reverse(p2 + 1, p2 + tot2 + 1);
    s1[0] = 0, s2[0] = 1;
    rep(i, 1, n){ 
        s1[i] = s1[i - 1] + p1[i], s2[i] = s2[i - 1] * p2[i];
        if(s1[i] > inf) s1[i] = inf;
        if(s2[i] > inf) s2[i] = inf;
    }
    ll l = 1, r = inf;
    realll ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {r=mid-1;ans=mid;}
        else l = mid + 1;
    }
    if(ans == 0) cout << "*\n";
    else  cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
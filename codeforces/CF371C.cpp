#include <bits/stdc++.h>
using namespace std;
int main() {
    string str; cin >> str;
    int cb=0, cs=0, cc=0;
    for(auto c : str) {
        if(c == 'B') cb++;
        else if (c == 'S') cs++;
        else cc++;
    }
    int nb,ns,nc,pb,ps,pc;
    cin>>nb>>ns>>nc>>pb>>ps>>pc;
    long long r; cin >> r;
    long long ans = 0;
    {
        int cur = 0x3f3f3f3f;
        if(cb) cur = min(cur, nb/cb);
        if(cs) cur = min(cur, ns/cs);
        if(cc) cur = min(cur, nc/cc);
        ans += cur;
        nb -= cur * cb;
        ns -= cur * cs;
        nc -= cur * cc;
    }
    while(cb&&nb || cs&&ns || cc&&nc) {
        int pnow = pb * max(0, cb - nb) + pc * max(0, cc - nc) + ps * max(0, cs - ns);
        if(pnow <= r) {
            r -= pnow;
            ans++;
            if(nb >= cb) nb -= cb;
            else nb = 0;
            if(nc >= cc) nc -= cc;
            else nc = 0;
            if(ns >= cs) ns -= cs;
            else ns = 0;
        } else break;
    }
    int p = cb * pb + cc * pc + cs * ps;
    ans += r / p;
    cout << ans << endl;
    return 0;
}
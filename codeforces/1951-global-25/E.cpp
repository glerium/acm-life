#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e6+10;
struct Manacher {
    int N, lc[maxn];
    char t[maxn];
    void init(char * s) {
        int n = strlen(s+1);
        t[0] = '^';
        t[n*2+1] = '#';
        t[n*2+2] = '\0';
        for(int i=1;i<=n;i++) {
            t[i*2] = s[i];
            t[i*2-1] = '#';
        }
        N = 2 * n + 1;
    }
    int operator[](int idx)const {
        return lc[idx];
    }
    void manacher() {
        lc[1] = 1;
        int k = 1;
        for(int i=2;i<=N;i++) {
            int p = k + lc[k] - 1;
            if(i <= p) {
                lc[i] = min(lc[2*k-i], p-i+1);
            }else{
                lc[i] = 1;
            }
            while(t[i+lc[i]] == t[i-lc[i]]) lc[i]++;
            if(i+lc[i] > k+lc[k])
                k = i;
        }
    }
} manacher;
char s[maxn];
int main() {
    int t; cin >> t;
    while(t--) {
        scanf("%s", s+1);
        manacher.init(s);
        manacher.manacher();
        auto check = [&](int l, int r) {
            return manacher[l+r] >= (r-l+1);
        };
        int n = strlen(s+1);
        if(!check(1,n)) {
            cout << "YES\n1\n" << s+1 << endl;
        }else{
            bool found = false;
            for(int i=1;i<n;i++) {
                if(!check(1,i) && !check(i+1,n)) {
                    cout << "YES\n2\n";
                    for(int j=1;j<=i;j++) cout << s[j];
                    cout << ' ';
                    for(int j=i+1;j<=n;j++) cout << s[j];
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "NO\n";
            }
        }
    }
}